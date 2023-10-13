#include "../include/limitOrderFactory.h"

std::unique_ptr<Order> LimitOrderFactory::createOrder(std::string symbol, OrderType t, int quantity, int id) {
    return std::make_unique<LimitOrder>(symbol, t, quantity, id);
}
