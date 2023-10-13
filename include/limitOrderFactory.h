#ifndef LIMIT_ORDER_FACTORY_H
#define LIMIT_ORDER_FACTORY_H

#include "orderFactory.h"
#include "limitOrder.h"

/**
 * @class LimitOrderFactory
 * @brief A derived class responsible for creating instances of limit orders.
 *
 * The LimitOrderFactory class inherits from the OrderFactory base class and is specifically designed to create instances
 * of limit orders with the provided attributes. It implements the createOrder method to generate limit order objects.
 */
class LimitOrderFactory : public OrderFactory {
public:
    /**
     * @brief Creates an instance of a limit order with the specified attributes.
     *
     * @param symbol The symbol or identifier of the stock associated with the limit order.
     * @param t The type of the limit order (BUY or SELL).
     * @param quantity The quantity of shares specified in the limit order.
     * @param id The unique identifier for the limit order.
     * @return A unique pointer to the newly created LimitOrder object.
     */
    std::unique_ptr<Order> createOrder(std::string symbol, OrderType t, int quantity, int id) override;

    /**
     * @brief Virtual destructor for the LimitOrderFactory class.
     */
    virtual ~LimitOrderFactory() {}
};

#endif // LIMIT_ORDER_FACTORY_H
