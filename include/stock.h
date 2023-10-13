#ifndef STOCK_H
#define STOCK_H

#include "includes.h"

/**
 * @class Stock
 * @brief An abstract base class representing a stock.
 *
 * The Stock class serves as an abstract base class for modeling various types of stocks in a trading system.
 * It defines common attributes and methods that is implemented by derived classes.
 */
class Stock {
public:
    /**
     * @brief Virtual destructor for the Stock class.
     */
    virtual ~Stock() {}

    /**
     * @brief Retrieves the current price of the stock.
     *
     * @return The current price of the stock.
     */
    virtual double getPrice() const = 0;

    /**
     * @brief Retrieves the trading volume (number of shares traded) of the stock.
     *
     * @return The trading volume of the stock.
     */
    virtual int getTradingVolume() const = 0;

    /**
     * @brief Sets the trading volume (number of shares traded) of the stock.
     *
     * @param volume The new trading volume of the stock.
     */
    virtual void setTradingVolume(int volume) = 0;

    /**
     * @brief Sets the price of the stock.
     *
     * @param price The new price of the stock.
     */
    virtual void setPrice(double price) = 0;

    /**
     * @brief Retrieves the symbol or identifier of the stock.
     *
     * @return The symbol of the stock.
     */
    virtual std::string getSymbol() const = 0;
};

#endif // STOCK_H

