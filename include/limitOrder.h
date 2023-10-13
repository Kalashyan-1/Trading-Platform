#ifndef LIMIT_ORDER_H
#define LIMIT_ORDER_H

#include "order.h"

/**
 * @class LimitOrder
 * @brief A derived class representing limit orders in a trading system.
 *
 * The LimitOrder class inherits from the Order base class and is specifically designed to represent limit orders.
 * It defines attributes and methods specific to limit orders and implements the virtual methods declared in the base class.
 */
class LimitOrder : public Order {
public:
    /**
     * @brief Constructs a LimitOrder object with specified attributes.
     *
     * @param sym The symbol or identifier of the stock associated with the limit order.
     * @param t The type of the limit order (BUY or SELL).
     * @param q The quantity of shares specified in the limit order.
     * @param id The unique identifier for the limit order.
     */
    LimitOrder(const std::string& sym, OrderType t, int q, int id);

    /**
     * @brief Default constructor for LimitOrder.
     */
    LimitOrder() = default;

    /**
     * @brief Virtual destructor for the LimitOrder class.
     */
    virtual ~LimitOrder() {}

    /**
     * @brief Checks if the limit order is a buy order.
     *
     * @return True if the limit order is a buy order; false if it is a sell order.
     */
    bool isBuyOrder() const override;

    /**
     * @brief Retrieves the quantity of shares specified in the limit order.
     *
     * @return The quantity of shares in the limit order.
     */
    int getQuantity() const override;

    /**
     * @brief Retrieves the symbol or identifier of the stock associated with the limit order.
     *
     * @return The symbol of the stock associated with the limit order.
     */
    std::string getSymbol() const override;

    /**
     * @brief Sets the price of the limit order.
     *
     * @param price The price to set for the limit order.
     */
    void setPrice(double price) override;

    /**
     * @brief Retrieves the price specified in the limit order.
     *
     * @return The price specified in the limit order.
     */
    double getPrice() const override;

    /**
     * @brief Serializes the limit order's information into JSON format.
     *
     * @return A JSON representation of the limit order.
     */
    nlohmann::json serialize() const override;

private:
    std::string symbol; ///< The symbol or identifier of the stock associated with the limit order.
    OrderType type; ///< The type of the limit order (BUY or SELL).
    double price; ///< The price specified in the limit order.
    int quantity; ///< The quantity of shares specified in the limit order.
    int traderId; ///< The unique identifier for the trader associated with the limit order.
};

#endif // LIMIT_ORDER_H
