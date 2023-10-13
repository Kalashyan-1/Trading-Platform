#ifndef ORDER_H
#define ORDER_H

#include "includes.h"

/**
 * @enum OrderType
 * @brief An enumeration representing the type of an order (BUY or SELL).
 *
 * The OrderType enum defines two order types: BUY and SELL, which are used to classify orders in a trading system.
 */
enum class OrderType {
    BUY, 
    SELL 
};

/**
 * @enum OrderStrategy
 * @brief An enumeration representing the strategy of an order (LIMIT or MARKET).
 *
 * The OrderStrategy enum defines two order strategies: LIMIT and MARKET, which are used to specify the strategy of orders in a trading system.
 */
enum class OrderStrategy {
    LIMIT, 
    MARKET 
};

/**
 * @class Order
 * @brief An abstract base class representing a trading order.
 *
 * The Order class serves as an abstract base class for modeling various types of trading orders in a trading system.
 * It defines common attributes and methods that must be implemented by derived classes.
 */
class Order {
public:
    /**
     * @brief Virtual destructor for the Order class.
     */
    virtual ~Order() {}

    /**
     * @brief Checks if the order is a buy order.
     *
     * @return True if the order is a buy order; false if it is a sell order.
     */
    virtual bool isBuyOrder() const = 0;

    /**
     * @brief Retrieves the quantity of shares specified in the order.
     *
     * @return The quantity of shares in the order.
     */
    virtual int getQuantity() const = 0;

    /**
     * @brief Retrieves the symbol or identifier of the stock associated with the order.
     *
     * @return The symbol of the stock associated with the order.
     */
    virtual std::string getSymbol() const = 0;

    /**
     * @brief Sets the price of the order.
     *
     * @param price The price to set for the order.
     */
    virtual void setPrice(double price) = 0;

    /**
     * @brief Retrieves the price specified in the order.
     *
     * @return The price specified in the order.
     */
    virtual double getPrice() const = 0;

    /**
     * @brief Serializes the order's information into JSON format.
     *
     * @return A JSON representation of the order.
     */
    virtual nlohmann::json serialize() const = 0;
};

#endif // ORDER_H
