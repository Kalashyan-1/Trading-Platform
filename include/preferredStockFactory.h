#ifndef PREFERRED_STOCK_FACTORY_H
#define PREFERRED_STOCK_FACTORY_H

#include "stockFactory.h"
#include "preferredStock.h"

/**
 * @class PreferredStockFactory
 * @brief A derived class responsible for creating instances of preferred stocks.
 *
 * The PreferredStockFactory class inherits from the StockFactory base class and is specifically designed to create instances
 * of preferred stocks with the provided attributes. It implements the createStock method to generate preferred stock objects.
 */
class PreferredStockFactory : public StockFactory {
public:
    /**
     * @brief Creates an instance of a preferred stock with the specified attributes.
     *
     * @param symbol The symbol or identifier of the preferred stock.
     * @param price The initial price of the preferred stock.
     * @param volume The initial trading volume (number of shares traded) of the preferred stock.
     * @param dividend The fixed dividend rate of the preferred stock.
     * @return A shared pointer to the newly created PreferredStock object.
     */
    std::shared_ptr<Stock> createStock(const std::string& symbol, double price, int volume, double dividend) override;

    /**
     * @brief Virtual destructor for the PreferredStockFactory class.
     */
    virtual ~PreferredStockFactory() {}
};

#endif // PREFERRED_STOCK_FACTORY_H
