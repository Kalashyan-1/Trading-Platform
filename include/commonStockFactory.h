#ifndef COMMON_STOCK_FACTORY_H
#define COMMON_STOCK_FACTORY_H

#include "stockFactory.h"
#include "commonStock.h"

/**
 * @class CommonStockFactory
 * @brief A derived class responsible for creating instances of common stocks.
 *
 * The CommonStockFactory class inherits from the StockFactory base class and is specifically designed to create instances
 * of common stocks with the provided attributes. It implements the createStock method to generate common stock objects.
 */
class CommonStockFactory : public StockFactory {
public:
    /**
     * @brief Creates an instance of a common stock with the specified attributes.
     *
     * @param symbol The symbol or identifier of the common stock.
     * @param price The initial price of the common stock.
     * @param volume The initial trading volume (number of shares traded) of the common stock.
     * @param dividend The last dividend paid for the common stock.
     * @return A shared pointer to the newly created CommonStock object.
     */
    std::shared_ptr<Stock> createStock(const std::string& symbol, double price, int volume, double dividend) override;

    /**
     * @brief Virtual destructor for the CommonStockFactory class.
     */
    virtual ~CommonStockFactory() {}
};

#endif // COMMON_STOCK_FACTORY_H
