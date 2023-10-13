#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include "order.h"

/**
 * @class OrderFactory
 * @brief An abstract base class for creating instances of trading orders.
 *
 * The OrderFactory class defines an interface for creating instances of trading orders with the provided attributes.
 * It declares a pure virtual method, createOrder, which must be implemented by derived classes to create specific order objects.
 */
class OrderFactory {
public:
    /**
     * @brief Creates an instance of a trading order with the specified attributes.
     *
     * @param symbol The symbol or identifier of the stock associated with the order.
     * @param t The type of the order (BUY or SELL).
     * @param quantity The quantity of shares specified in the order.
     * @param id The unique identifier for the order.
     * @return A unique pointer to the newly created Order object.
     */
    virtual std::unique_ptr<Order> createOrder(std::string symbol, OrderType t, int quantity, int id) = 0;

    /**
     * @brief Virtual destructor for the OrderFactory class.
     */
    virtual ~OrderFactory() {}
};

#endif // ORDER_FACTORY_H
