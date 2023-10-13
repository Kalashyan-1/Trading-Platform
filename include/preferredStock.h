#ifndef PREFERRED_STOCK_H
#define PREFERRED_STOCK_H

#include "stock.h"

/**
 * @class PreferredStock
 * @brief A derived class representing preferred stocks.
 *
 * The PreferredStock class inherits from the Stock base class and represents preferred stocks in a trading system.
 * It defines attributes specific to preferred stocks and implements the virtual methods defined in the base class.
 */
class PreferredStock : public Stock {
public:
    /**
     * @brief Constructs a PreferredStock object with specified attributes.
     *
     * @param sym The symbol or identifier of the preferred stock.
     * @param fixedDiv The fixed dividend rate of the preferred stock.
     * @param pr The current price of the preferred stock.
     * @param trVol The trading volume (number of shares traded) of the preferred stock.
     */
    PreferredStock(const std::string& sym, double fixedDiv, double pr, int trVol);

    /**
     * @brief Default constructor for PreferredStock.
     */
    PreferredStock() = default;

    /**
     * @brief Virtual destructor for the PreferredStock class.
     */
    virtual ~PreferredStock() {}

    /**
     * @brief Retrieves the current price of the preferred stock.
     *
     * @return The current price of the preferred stock.
     */
    double getPrice() const override;

    /**
     * @brief Retrieves the trading volume (number of shares traded) of the preferred stock.
     *
     * @return The trading volume of the preferred stock.
     */
    int getTradingVolume() const override;

    /**
     * @brief Sets the trading volume (number of shares traded) of the preferred stock.
     *
     * @param volume The new trading volume of the preferred stock.
     */
    void setTradingVolume(int volume) override;

    /**
     * @brief Sets the price of the preferred stock.
     *
     * @param price The new price of the preferred stock.
     */
    void setPrice(double price) override;

    /**
     * @brief Retrieves the symbol or identifier of the preferred stock.
     *
     * @return The symbol of the preferred stock.
     */
    std::string getSymbol() const override;

private:
    std::string symbol; ///< The symbol or identifier of the preferred stock.
    double fixedDividend; ///< The fixed dividend rate of the preferred stock.
    double price; ///< The current price of the preferred stock.
    int tradingVolume; ///< The trading volume (number of shares traded) of the preferred stock.
};

#endif // PREFERRED_STOCK_H

