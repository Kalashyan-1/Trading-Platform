#include "../include/platformPausedState.h"

PlatformPausedState::PlatformPausedState(TradingPlatform& platform) {
    auto traders = platform.getTraders();
    for (const auto& t : traders) {
        traderBalance[t.getName()] = t.getBalance();
    }

    auto stocks = platform.getStocks();
    for (const auto& s : stocks) {
        stockPrice[s->getSymbol()] = s->getPrice();
    }
}

void PlatformPausedState::takeCurrentState(TradingPlatform& platform) {
    platform.pauseThreads();
    printCurrentState(platform);
    platform.resumeThreads(); 
}

void PlatformPausedState::printCurrentState(TradingPlatform& platform) {
    auto traders = platform.getTraders();

    std::cout << "\n\n\n";
    std::cout << std::left << std::setw(20) << "Name" << std::setw(10) << "Balance" << std::endl;
    std::cout << std::string(30, '-') << std::endl;

    for (const auto& t : traders) {
        if (traderBalance.find(t.getName()) == traderBalance.end()) {
            traderBalance[t.getName()] = t.getBalance();
            std::cout << std::setw(20) << t.getName() << std::setw(10) << t.getBalance() << std::endl;
        } else {
            if (traderBalance[t.getName()] < t.getBalance()) {
                std::cout << "\033[32m"; 
                std::cout << std::setw(20) << t.getName() << std::setw(10) << t.getBalance() << std::endl;
                std::cout << "\033[0m";
            } else if(traderBalance[t.getName()] > t.getBalance()){
                std::cout << "\033[31m"; 
                std::cout << std::setw(20) << t.getName() << std::setw(10) << t.getBalance() << std::endl;
                std::cout << "\033[0m"; 
            } else {
                std::cout << std::setw(20) << t.getName() << std::setw(10) << t.getBalance() << std::endl;
            }
            traderBalance[t.getName()] = t.getBalance();
        }
    }
    std::cout << std::string(30, '-') << std::endl;
    std::cout << "\n\n\n";
    auto stocks = platform.getStocks();

    std::cout << std::left << std::setw(10) << "Symbol" << std::setw(10) << "Price" << std::endl;
    std::cout << std::string(20, '-') << std::endl;
    std::string sym;
    double pr;
    for (const auto& s : stocks) {
        sym = s->getSymbol();
        pr = s->getPrice();
        if (stockPrice[sym] < s->getPrice()) {
            std::cout << "\033[32m"; 
            std::cout << std::setw(10) << sym << std::setw(10) << pr << std::endl;
            std::cout << "\033[0m";
        } else if (stockPrice[sym] > s->getPrice()){
            std::cout << "\033[31m"; 
            std::cout << std::setw(10) << sym << std::setw(10) << pr << std::endl;
            std::cout << "\033[0m";
        } else {
            std::cout << std::setw(10) << sym << std::setw(10) << pr << std::endl;
        }
        stockPrice[sym] = pr;
    }
    std::cout << "\n\n\n";
}
