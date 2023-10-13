#ifndef COMMON_STOCK_H
#define COMMON_STOCK_H

#include "stock.h"

/**
 * @class CommonStock
 * @brief A derived class representing common stocks.
 *
 * The CommonStock class inherits from the Stock base class and represents common stocks in a trading system.
 * It defines attributes specific to common stocks and implements the virtual methods defined in the base class.
 */
class CommonStock : public Stock {
public:
    /**
     * @brief Constructs a CommonStock object with specified attributes.
     *
     * @param sym The symbol or identifier of the common stock.
     * @param lastDiv The last dividend paid for the common stock.
     * @param pr The current price of the common stock.
     * @param trVol The trading volume (number of shares traded) of the common stock.
     */
    CommonStock(const std::string& sym, double lastDiv, double pr, int trVol);

    /**
     * @brief Virtual destructor for the CommonStock class.
     */
    virtual ~CommonStock() {}

    /**
     * @brief Retrieves the current price of the common stock.
     *
     * @return The current price of the common stock.
     */
    double getPrice() const override;

    /**
     * @brief Retrieves the trading volume (number of shares traded) of the common stock.
     *
     * @return The trading volume of the common stock.
     */
    int getTradingVolume() const override;

    /**
     * @brief Sets the trading volume (number of shares traded) of the common stock.
     *
     * @param volume The new trading volume of the common stock.
     */
    void setTradingVolume(int volume) override;

    /**
     * @brief Sets the price of the common stock.
     *
     * @param price The new price of the common stock.
     */
    void setPrice(double price) override;

    /**
     * @brief Retrieves the symbol or identifier of the common stock.
     *
     * @return The symbol of the common stock.
     */
    std::string getSymbol() const override;

private:
    std::string symbol; ///< The symbol or identifier of the common stock.
    double lastDividend; ///< The last dividend paid for the common stock.
    double price; ///< The current price of the common stock.
    int tradingVolume; ///< The trading volume (number of shares traded) of the common stock.
};

#endif // COMMON_STOCK_H

