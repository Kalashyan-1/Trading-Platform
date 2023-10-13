#ifndef STOCK_FACTORY_H
#define STOCK_FACTORY_H

#include "stock.h"

/**
 * @class StockFactory
 * @brief An abstract base class for creating instances of stocks.
 *
 * The StockFactory class defines an interface for creating instances of stocks with the provided attributes.
 * It declares a pure virtual method, createStock, which must be implemented by derived classes to create specific stock objects.
 */
class StockFactory {
public:
    /**
     * @brief Creates an instance of a stock with the specified attributes.
     *
     * @param symbol The symbol or identifier of the stock.
     * @param price The initial price of the stock.
     * @param volume The initial trading volume (number of shares traded) of the stock.
     * @param dividend The dividend rate or fixed dividend of the stock (specific to stock type).
     * @return A shared pointer to the newly created Stock object.
     */
    virtual std::shared_ptr<Stock> createStock(const std::string& symbol, double price, int volume, double dividend) = 0;

    /**
     * @brief Virtual destructor for the StockFactory class.
     */
    virtual ~StockFactory() {}
};

#endif // STOCK_FACTORY_H
