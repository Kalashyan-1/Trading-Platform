#include "../include/platformInitializer.h"

PlatformInitializer::PlatformInitializer(TradingPlatform& platform) {
    int chois;
    std::cout << "\n\n\n\n";
    std::cout << "\033[32m";
    std::cout << " /$$$$$$$$                       /$$ /$$                           /$$$$$$$  /$$             /$$      /$$$$$$                                 \n";
    std::cout << "|__  $$__/                      | $$|__/                          | $$__  $$| $$            | $$     /$$__  $$                                \n";
    std::cout << "   | $$  /$$$$$$  /$$$$$$   /$$$$$$$ /$$ /$$$$$$$   /$$$$$$       | $$  \\ $$| $$  /$$$$$$  /$$$$$$  | $$  \\__//$$$$$$   /$$$$$$  /$$$$$$/$$$$ \n";
    std::cout << "   | $$ /$$__  $$|____  $$ /$$__  $$| $$| $$__  $$ /$$__  $$      | $$$$$$$/| $$ |____  $$|_  $$_/  | $$$$   /$$__  $$ /$$__  $$| $$_  $$_  $$\n";
    std::cout << "   | $$| $$  \\__/ /$$$$$$$| $$  | $$| $$| $$  \\ $$| $$  \\ $$      | $$____/ | $$  /$$$$$$$  | $$    | $$_/  | $$  \\ $$| $$  \\__/| $$ \\ $$ \\ $$\n";
    std::cout << "   | $$| $$      /$$__  $$| $$  | $$| $$| $$  | $$| $$  | $$      | $$      | $$ /$$__  $$  | $$ /$$| $$    | $$  \\ $$| $$      | $$ | $$ | $$\n";
    std::cout << "   | $$| $$     |  $$$$$$$|  $$$$$$$| $$| $$  | $$|  $$$$$$$      | $$      | $$|  $$$$$$$  |  $$$$/| $$    |  $$$$$$/| $$      | $$ | $$ | $$\n";
    std::cout << "   |__/|__/      \\_______/ \\_______/|__/|__/  |__/ \\____  $$      |__/      |__/ \\_______/   \\___/  |__/     \\______/ |__/      |__/ |__/ |__/\n";
    std::cout << "                                                   /$$  \\ $$                                                                                  \n";
    std::cout << "                                                  |  $$$$$$/                                                                                   \n";
    std::cout << "                                                   \\______/                                                                                    \n";
    std::cout << "\033[0m";
    std::cout << "\n\n\n\n";




    int dur = 0;
    std::string duration = "";
    while (true) {
        try
        {
            std::cerr << "\033[33m";
            std::cerr << "Enter duration of program in seconds: ";
            std::cerr << "\033[0m";
            std::cout << "\n";
            std::cin.putback(' ');

            std::cin >> duration;
            std::cout << duration;
            dur = std::stoi(duration); 
            if (dur < 10) {
                throw std::runtime_error("Trading Platform should work at least 10 sec");
            }
            platform.setDuration(dur);
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\033[31m";
            std::cerr << e.what() << '\n';
            std::cerr << "\033[0m";
            std::cout << std::endl;
        }
    }
    
    while (true) {
        std::cout << "\033[33m";
        std::cout << "Enter 1 to initialize platform from command line:" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter 2 to initialize platform from file" << std::endl;
        std::cout << "\033[0m";
        std::cout << std::endl;
        std::cin.get();

        std::cin >> chois;
        if (chois == 1) {
            commandLineInit(platform);
            break;
        } else if (chois == 2){
            fileInit(platform);
            break;
        }
    }
}


void PlatformInitializer::commandLineInit(TradingPlatform& platform) {
    int numTraders;
    std::cout << "\033[33m";
    std::cout << "Enter the number of traders: ";
    std::cout << "\033[0m";
    std::cin >> numTraders;
    std::cout << std::endl;


    std::filesystem::path filePath = std::filesystem::current_path().parent_path() / "src" / "platformInfo.json";
    std::fstream file(filePath , std::ios::in);

    if (!file.is_open()) {
        std::cerr << "Failed to open JSON file: " << filePath << std::endl;
        return;
    }

    int id;
    nlohmann::json jsonConfig;
    file >> jsonConfig;

    if (jsonConfig.contains("traders") && jsonConfig["traders"].is_array()) {
        for (const auto& traderJson : jsonConfig["traders"]) {
            if (traderJson.contains("id") && traderJson.contains("name") && traderJson.contains("balance")) {
                id = traderJson["id"];
            }
        }
    }
    ++id;
        std::string name = "";
        std::string balance = "";
        double b = 0.0;
    std::getline(std::cin, name);

    for (int i = 0; i < numTraders;) {
        std::cout << "\033[33m";
        std::cout << "Enter Trader " << i + 1 << " details:" << std::endl;
        std::cout << "Name: ";
        std::cout << "\033[0m";
        std::getline(std::cin, name);
        std::cout << '\n';

        std::cout << "\033[33m";
        std::cout << "Balance: ";
        std::cout << "\033[0m";

        
        std::cin.putback(' ');

        std::getline(std::cin, balance);

        try {
            double b = std::stod(balance);
            platform.getTraders().emplace_back(name, b, id + i);
            ++i;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
}


void PlatformInitializer::fileInit(TradingPlatform& platform) {
    std::filesystem::path filePath = std::filesystem::current_path().parent_path() / "src" / "platformInfo.json";
    std::fstream file(filePath , std::ios::in);

    if (!file.is_open()) {
        std::cerr << "Failed to open JSON file: " << filePath << std::endl;
        return;
    }

    nlohmann::json jsonConfig;
    file >> jsonConfig;

    if (jsonConfig.contains("traders") && jsonConfig["traders"].is_array()) {
        for (const auto& traderJson : jsonConfig["traders"]) {
            if (traderJson.contains("id") && traderJson.contains("name") && traderJson.contains("balance")) {
                int id = traderJson["id"];
                std::string name = traderJson["name"];
                double balance = traderJson["balance"];
                Trader(name, balance, id);
                platform.getTraders().emplace_back(name, balance, id);
            }
        }
    }


    if (jsonConfig.contains("orderBook")) {
        const auto& orderBookJson = jsonConfig["orderBook"];
        if (orderBookJson.contains("buyOrders") && orderBookJson["buyOrders"].contains("limitOrders")) {
            initializeOrdersFromJSON(orderBookJson["buyOrders"]["limitOrders"], platform.getOrderBook().getBuyOrders(), OrderStrategy::LIMIT, OrderType::BUY);
        }
        if (orderBookJson.contains("buyOrders") && orderBookJson["buyOrders"].contains("marketOrders")) {
            initializeOrdersFromJSON(orderBookJson["buyOrders"]["marketOrders"], platform.getOrderBook().getBuyOrders(), OrderStrategy::MARKET, OrderType::BUY);
        }
        if (orderBookJson.contains("sellOrders") && orderBookJson["sellOrders"].contains("limitOrders")) {
            initializeOrdersFromJSON(orderBookJson["sellOrders"]["limitOrders"], platform.getOrderBook().getSellOrders(), OrderStrategy::LIMIT, OrderType::SELL);
        }
        if (orderBookJson.contains("sellOrders") && orderBookJson["sellOrders"].contains("marketOrders")) {
            initializeOrdersFromJSON(orderBookJson["sellOrders"]["marketOrders"], platform.getOrderBook().getSellOrders(), OrderStrategy::MARKET, OrderType::SELL);
        }
    }
}



void PlatformInitializer::initializeOrdersFromJSON(const nlohmann::json& ordersJson, std::vector<std::shared_ptr<Order>>& orders, OrderStrategy orderStrategy, OrderType orderType) {
    if (ordersJson.is_array()) {
        for (const auto& orderJson : ordersJson) {
            if (orderJson.contains("symbol") && orderJson.contains("quantity") && orderJson.contains("traderID")) {
                std::string symbol = orderJson["symbol"];
                int quantity = orderJson["quantity"];
                int traderID = orderJson["traderID"];

                std::shared_ptr<Order> order;
                if (orderStrategy == OrderStrategy::LIMIT) {
                    double tmp = orderJson["price"];
                    double price = orderJson.contains("price") ? tmp : 0.0;
                    order = std::make_shared<LimitOrder>(symbol, orderType, quantity, traderID);
                    order->setPrice(price);
                } else {
                    order = std::make_shared<MarketOrder>(symbol, orderType, quantity, traderID);
                }
                orders.push_back(order);
            }
        }
    }
}

