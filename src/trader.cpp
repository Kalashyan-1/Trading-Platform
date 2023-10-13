#include "../include/trader.h"


Trader::Trader(const std::string& n, double initialBalance, int ID) 
    : name{n}, balance{initialBalance}, id{ID}  {}

nlohmann::json Trader::serialize() const {
    return {
        {"id", id},
        {"name", name},
        {"balance", balance}
    };
}

void Trader::buy(MarketDataGenerator& dataGenerator, OrderBook& book, const std::string& symbol, int quantity) {
    double currentPrice = dataGenerator.getStockPrice(symbol);
    if (currentPrice == 0.0) return;
    double orderCost = quantity * currentPrice;
    if (orderCost > balance) {
        return;
    }

    std::shared_ptr<Order> order = marketStrategyDecision(OrderType::BUY, symbol, quantity, currentPrice);
     
    if (!order) return;
    balance -= orderCost;

    if (portfolio.find(symbol) == portfolio.end()) {
        portfolio[symbol] = quantity;
    } else {
        portfolio[symbol] += quantity;
    }

    book.processOrder(order);

}

void Trader::sell(MarketDataGenerator& dataGenerator, OrderBook& book, const std::string& symbol, int quantity) {
    double currentPrice = dataGenerator.getStockPrice(symbol);
    
    if (portfolio.find(symbol) == portfolio.end()) {
        return;
    }

    if (quantity > portfolio[symbol]) {
        quantity = portfolio[symbol];
    }

    double saleProceeds = quantity * currentPrice;

    std::shared_ptr<Order> order = marketStrategyDecision(OrderType::SELL, symbol, quantity, currentPrice);
     
    if (!order) return;
    balance += saleProceeds;
    portfolio[symbol] -= quantity;

    if (portfolio[symbol] == 0) {
        portfolio.erase(symbol);
    }

    book.processOrder(order);
}

void Trader::updateBalance(double amount) {
    balance += amount;
}


std::shared_ptr<Order> Trader::marketStrategyDecision(OrderType type, const std::string& symbol, int quantity, double currentPrice) {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_int_distribution<int> dist(0, 2);

    int dec = dist(gen);

    std::shared_ptr<OrderFactory> marketfactory = std::make_shared<MarketOrderFactory>();
    std::shared_ptr<OrderFactory> limitfactory = std::make_shared<LimitOrderFactory>();

    std::shared_ptr<Order> order = nullptr;

    if (dec == 1) {
        order = marketfactory->createOrder(symbol, type, quantity, id);
    } else if (dec == 2) {
        double limitPrice = currentPrice * (0.9 + (0.2 * dist(gen))); 
        order = limitfactory->createOrder(symbol, type, quantity, id);
        order->setPrice(limitPrice);
    }

    return order;
}

std::pair<std::string, int> Trader::getStockVolumeFromPortfolio() {
    return *(portfolio.begin());
}

bool Trader::isPortfolioEmpty() {
    return portfolio.empty();
}

std::string Trader::getName() const {
    return name;
}

double Trader::getBalance() const {
    return balance;
}

std::ostream& operator<<(std::ostream& os, const Trader& trader) {
    os << "Trader " << trader.name << ": Balance $" << trader.balance << std::endl;
    return os;
}