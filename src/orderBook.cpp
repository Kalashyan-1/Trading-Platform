#include "../include/orderBook.h"
#include <iostream>


OrderBook& OrderBook::getInstance() {
    static std::unique_ptr<OrderBook> instance = nullptr;
    static std::mutex instanceMutex;
    
    if (instance == nullptr) {
        std::lock_guard<std::mutex> lock(instanceMutex);
        if (instance == nullptr) {
            instance.reset(new OrderBook());
        }
    }
    return *instance;
}

void OrderBook::processOrder(std::shared_ptr<Order> order) {
    std::lock_guard<std::mutex> lock(bookMutex); 
    std::string sym = order->getSymbol();
    int quantity = order->getQuantity();
    if (quantity == 0) return;
    if (order->isBuyOrder()) {
        buyOrders.push_back(order);
        buySellQuantity[sym].first += quantity;
    } else {
        sellOrders.push_back(order);
        buySellQuantity[sym].second = quantity;
    }
    auto p =  buySellQuantity[sym];
    if (p.first == p.second) {
        buySellQuantity.erase(sym);
        removeFromOrderBook(buyOrders, sym);
        removeFromOrderBook(sellOrders, sym);
    }
}

void OrderBook::removeFromOrderBook(std::vector<std::shared_ptr<Order>> ord, const std::string& sym) {
    auto it = ord.begin();
    while (it != ord.end()) {
        if ((*it)->getSymbol() == sym) {
            it = ord.erase(it);
        } else {
            ++it;
        }
    }
}
std::vector<std::shared_ptr<Order>>& OrderBook::getBuyOrders() {
    std::lock_guard<std::mutex> lock(bookMutex); 
    return buyOrders;
}

std::vector<std::shared_ptr<Order>>& OrderBook::getSellOrders() {
    std::lock_guard<std::mutex> lock(bookMutex); 
    return sellOrders;
}

std::string OrderBook::getTraderName(int traderID) const {
    std::lock_guard<std::mutex> lock(bookMutex); 
    auto it = traderNames.find(traderID);
    if (it != traderNames.end()) {
        return it->second; 
    } else {
        return "Unknown Trader"; 
    }
}


nlohmann::json OrderBook::serialize() const {
    nlohmann::json buyLimitOrders, buyMarketOrders, sellLimitOrders, sellMarketOrders;

    for (const std::shared_ptr<Order>& order : buyOrders) {
        if (std::dynamic_pointer_cast<LimitOrder>(order)) {
            buyLimitOrders.push_back(order->serialize());
        } else if (std::dynamic_pointer_cast<MarketOrder>(order)) {
            buyMarketOrders.push_back(order->serialize());
        }
    }

    for (const auto& order : sellOrders) {
        if (std::dynamic_pointer_cast<LimitOrder>(order)) {
            sellLimitOrders.push_back(order->serialize());
        } else if (std::dynamic_pointer_cast<MarketOrder>(order)) {
            sellMarketOrders.push_back(order->serialize());
        }
    }

    nlohmann::json buyOrdersJson = {
        {"limitOrders", buyLimitOrders},
        {"marketOrders", buyMarketOrders}
    };

    nlohmann::json sellOrdersJson = {
        {"limitOrders", sellLimitOrders},
        {"marketOrders", sellMarketOrders}
    };

    return {
        {"buyOrders", buyOrdersJson},
        {"sellOrders", sellOrdersJson}
    };
}


std::ostream& operator<<(std::ostream& os, const OrderBook& orderBook) {
    os << "Order Book:" << std::endl;
    const auto& buyOrders = orderBook.buyOrders;
    const auto& sellOrders = orderBook.sellOrders;

    os << "Buy Orders:" << std::endl;
    for (const auto& order : buyOrders) {
        os << " - " << order->getQuantity() << " shares of " << order->getSymbol() << " at $" << order->getPrice() << std::endl;
    }

    os << "Sell Orders:" << std::endl;
    for (const auto& order : sellOrders) {
        os << " - " << order->getQuantity() << " shares of " << order->getSymbol() << " at $" << order->getPrice() << std::endl;
    }
    return os;
}