#include "../include/tradingPlatform.h"
#include "../include/platformPausedState.h"

TradingPlatform::TradingPlatform(OrderBook& book) 
    : orderBook(book), pause{true}, stopThreads{false} {
        state = std::make_unique<PlatformPausedState>(*this);
    }

TradingPlatform::~TradingPlatform() {
    saveState();
}

void TradingPlatform::startTradingSimulation() {
    for (int i = 0; i < traders.size(); ++i) {
        workerThreads.emplace_back(&TradingPlatform::workerThreadFunction, this);
    }

    simulationLoop();
}

void TradingPlatform::simulationLoop() {
    auto lastStateUpdateTime = std::chrono::steady_clock::now();
    auto start = lastStateUpdateTime;
    while (true) {
        auto currentTime = std::chrono::steady_clock::now();

        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastStateUpdateTime);
        
        if (std::chrono::duration_cast<std::chrono::seconds>(currentTime - start) >= std::chrono::seconds(dataGenerator.getDuration())) break;
        
        if (elapsedTime >= std::chrono::seconds(5)) {
            dataGenerator.startSimulation();
            state->takeCurrentState(*this);
            lastStateUpdateTime = currentTime;
        }
        for (Trader& trader : traders) {
            std::function<void()> traderAction = [this, &trader]() {
                handleTraderActions(trader);
            };
            {
                std::unique_lock<std::mutex> lock(taskQueueMutex);
                taskQueue.push(traderAction);
            }
            taskAvailable.notify_one();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

}

void TradingPlatform::handleTraderActions(Trader& trader) {
    std::random_device rd;
    std::mt19937 gen(rd());

    auto stocks = dataGenerator.getStocks();
    std::uniform_int_distribution<int> dist(0, stocks.size() - 1);
    int dec = dist(gen);

    if (dec <= static_cast<int>(stocks.size()) / 2) {
        trader.buy(dataGenerator, orderBook, stocks[dec]->getSymbol(), dec / 2);
    } else {
        if (trader.isPortfolioEmpty()) return;
        auto pair = trader.getStockVolumeFromPortfolio();
        if (pair.second == 0) {
            trader.updateBalance(dec * 1000);
            return;
        };
        trader.sell(dataGenerator, orderBook, pair.first, pair.second);
    }
}

void TradingPlatform::workerThreadFunction() {
    while (!stopThreads) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(taskQueueMutex);
            taskAvailable.wait(lock, [this] { return !taskQueue.empty() || stopThreads; });
            if (stopThreads) return;  
            if (pause) {
                pauseCondition.wait(lock, [this] { return !pause; });
                continue;
            }
            task = taskQueue.front();
            taskQueue.pop();
        }
        task(); 
    }
}

std::vector<Trader>& TradingPlatform::getTraders() {
    return traders;
}


OrderBook& TradingPlatform::getOrderBook() {
    return orderBook;
}


void TradingPlatform::pauseThreads() {
    std::unique_lock<std::mutex> lock(pauseMutex);
    pause = true; 
}

void TradingPlatform::resumeThreads() {
    std::unique_lock<std::mutex> lock(pauseMutex);
    pause = false;
    pauseCondition.notify_all();
}

std::vector<std::shared_ptr<Stock>> TradingPlatform::getStocks() const {
    return dataGenerator.getStocks();
}


nlohmann::json TradingPlatform::serialize() const {
    nlohmann::json tradersJson;
    for (const auto& trader : traders) {
        tradersJson.push_back(trader.serialize());
    }

    nlohmann::json platformJson = {
        {"traders", tradersJson},
        {"orderBook", orderBook.serialize()}
    };

    return platformJson;
}

void TradingPlatform::stopThread() {
    stopThreads = true;
    {
        std::unique_lock<std::mutex> lock(taskQueueMutex);
        taskAvailable.notify_all();
    }
    for (std::thread& thread : workerThreads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

void TradingPlatform::saveState(){
    nlohmann::json platformJson = serialize();
    std::filesystem::path filePath = std::filesystem::current_path().parent_path() / "src" / "platformState.json";
    std::ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        outputFile << std::setw(4) << platformJson;
        outputFile.close();
        std::cout << "Platform state saved to: platformState.json" << std::endl;
    } else {
        std::cerr << "Failed to open JSON file for saving" << std::endl;
    }
    stopThread();
}

void TradingPlatform::setDuration(int d) {
    dataGenerator.setDuration(d);
}