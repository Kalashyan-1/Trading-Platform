#include "../include/limitOrder.h"

LimitOrder::LimitOrder(const std::string& sym, OrderType t, int q, int id) 
    : symbol{sym}, type{t}, quantity{q}, traderId{id} {}


bool LimitOrder::isBuyOrder() const {
    return (type == OrderType::BUY);
}


int LimitOrder::getQuantity() const {
    return quantity;
}


std::string LimitOrder::getSymbol() const {
    return symbol;
}


void LimitOrder::setPrice(double p) {
    price = p;
}


double LimitOrder::getPrice() const {
    return price;
}


nlohmann::json LimitOrder::serialize() const {
    return {
        {"symbol", symbol},
        {"quantity", quantity},
        {"price", price},
        {"traderID", traderId}
    };
}