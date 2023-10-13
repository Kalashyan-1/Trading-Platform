#include "../include/marketOrder.h"

MarketOrder::MarketOrder(const std::string& sym, OrderType t,int q, int id)
    : symbol{sym}, type{t}, quantity{q}, traderId{id} {}


bool MarketOrder::isBuyOrder() const {
    return (type == OrderType::BUY);
}

void MarketOrder::setPrice(double) {}

int MarketOrder::getQuantity() const {
    return quantity;
}

std::string MarketOrder::getSymbol() const {
    return symbol;
}

double MarketOrder::getPrice() const {return -1.0;}

nlohmann::json MarketOrder::serialize() const {
    return {
        {"symbol", symbol},
        {"quantity", quantity},
        {"traderID", traderId}
    };
}