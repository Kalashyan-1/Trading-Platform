#ifndef MARKET_ORDER_FACTORY_H
#define MARKET_ORDER_FACTORY_H

#include "orderFactory.h"
#include "marketOrder.h"

/**
 * @class MarketOrderFactory
 * @brief A derived class responsible for creating instances of market orders.
 *
 * The MarketOrderFactory class inherits from the OrderFactory base class and is specifically designed to create instances
 * of market orders with the provided attributes. It implements the createOrder method to generate market order objects.
 */
class MarketOrderFactory : public OrderFactory {
public:
    /**
     * @brief Creates an instance of a market order with the specified attributes.
     *
     * @param symbol The symbol or identifier of the stock associated with the market order.
     * @param t The type of the market order (BUY or SELL).
     * @param quantity The quantity of shares specified in the market order.
     * @param id The unique identifier for the market order.
     * @return A unique pointer to the newly created MarketOrder object.
     */
    std::unique_ptr<Order> createOrder(std::string symbol, OrderType t, int quantity, int id) override;

    /**
     * @brief Virtual destructor for the MarketOrderFactory class.
     */
    virtual ~MarketOrderFactory() {}
};

#endif // MARKET_ORDER_FACTORY_H
