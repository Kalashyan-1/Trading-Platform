#include "../include/marketOrderFactory.h"

std::unique_ptr<Order> MarketOrderFactory::createOrder(std::string symbol, OrderType t, int quantity, int id) {
    return std::make_unique<MarketOrder>(symbol, t, quantity, id);
}
