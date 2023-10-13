#ifndef MARKET_ORDER_H
#define MARKET_ORDER_H

#include "order.h"

/**
 * @class MarketOrder
 * @brief A derived class representing market orders in a trading system.
 *
 * The MarketOrder class inherits from the Order base class and is specifically designed to represent market orders.
 * It defines attributes and methods specific to market orders and implements the virtual methods declared in the base class.
 */
class MarketOrder : public Order {
public:
    /**
     * @brief Constructs a MarketOrder object with specified attributes.
     *
     * @param sym The symbol or identifier of the stock associated with the market order.
     * @param t The type of the market order (BUY or SELL).
     * @param q The quantity of shares specified in the market order.
     * @param id The unique identifier for the market order.
     */
    MarketOrder(const std::string& sym, OrderType t, int q, int id);

    /**
     * @brief Default constructor for MarketOrder.
     */
    MarketOrder() = default;

    /**
     * @brief Virtual destructor for the MarketOrder class.
     */
    virtual ~MarketOrder() {}

    /**
     * @brief Checks if the market order is a buy order.
     *
     * @return True if the market order is a buy order; false if it is a sell order.
     */
    bool isBuyOrder() const override;

    /**
     * @brief Sets the price of the market order (not applicable for market orders).
     *
     * @param price The price to set for the market order (unused for market orders).
     */
    void setPrice(double price) override;

    /**
     * @brief Retrieves the quantity of shares specified in the market order.
     *
     * @return The quantity of shares in the market order.
     */
    int getQuantity() const override;

    /**
     * @brief Retrieves the symbol or identifier of the stock associated with the market order.
     *
     * @return The symbol of the stock associated with the market order.
     */
    std::string getSymbol() const override;

    /**
     * @brief Retrieves the price specified in the market order (not applicable for market orders).
     *
     * @return The price specified in the market order (unused for market orders).
     */
    double getPrice() const override;

    /**
     * @brief Serializes the market order's information into JSON format.
     *
     * @return A JSON representation of the market order.
     */
    nlohmann::json serialize() const override;

private:
    std::string symbol; ///< The symbol or identifier of the stock associated with the market order.
    OrderType type; ///< The type of the market order (BUY or SELL).
    int quantity; ///< The quantity of shares specified in the market order.
    int traderId; ///< The unique identifier for the trader associated with the market order.
};

#endif // MARKET_ORDER_H
