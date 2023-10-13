#include "../include/marketDataGenerator.h"
#include <filesystem>
MarketDataGenerator::MarketDataGenerator(int d)
        : duration(d) 
{
    loadStockInfoFromJSON("stockInfo.json");
}
 
void MarketDataGenerator::startSimulation() {
       const double priceIncreaseFactor = 10; 

        for (auto& stock : stocks) {
            double currentPrice = stock->getPrice();

            double priceChange = generateRandomPriceChange(currentPrice);

            double newPrice = currentPrice + (priceChange * priceIncreaseFactor);
            stock->setPrice(newPrice);

            int tradingVolume = rand() % 1000 + 1; 
            stock->setTradingVolume(tradingVolume);

        }
}

double MarketDataGenerator::generateRandomPriceChange(double currentPrice) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distribution(-0.5, 2.0);
    double percentageChange = distribution(gen);
    return currentPrice * (percentageChange / 100.0);
}

double MarketDataGenerator::getStockPrice(const std::string& sym) {
    for (auto& s: stocks) {
        if (s->getSymbol() == sym) {
            return s->getPrice();
        }
    }
    return 0.0;
}

std::vector<std::shared_ptr<Stock>> MarketDataGenerator::getStocks() const {
    return stocks;
}

void MarketDataGenerator::loadStockInfoFromJSON(const std::string& filename) {
    std::filesystem::path filePath = std::filesystem::current_path().parent_path() / "src" / filename;
    std::fstream inputFile(filePath , std::ios::in);
    if (inputFile.is_open()) {
        nlohmann::json stockInfo;
        inputFile >> stockInfo;
        std::shared_ptr<StockFactory> commonfactory = std::make_shared<CommonStockFactory>();
        std::shared_ptr<StockFactory> preffactory = std::make_shared<PreferredStockFactory>();
        for (const auto& stockData : stockInfo) {
            std::string symbol = stockData["symbol"];
            double price = stockData["price"];
            int volume = stockData["volume"];
            std::string type = stockData["type"];
            double dividend = stockData["dividend"];

            std::shared_ptr<Stock> stock;
            
            if (type == "Common") {
                stock = std::make_shared<CommonStock>(symbol, dividend, price, volume);
            } else if (type == "Preferred") {
                stock = std::make_shared<PreferredStock>(symbol, dividend, price, volume);
            }
            if (stock) {
                stocks.emplace_back(stock);
            } else {
                std::cout << "Failed to load Stock Info" << std::endl;
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Failed to open file for reading: " << filename << std::endl;
    }
}

void MarketDataGenerator::setDuration(int d) {
    duration = d;
}

int MarketDataGenerator::getDuration() const {
    return duration;
}