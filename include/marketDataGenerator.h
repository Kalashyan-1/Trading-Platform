#ifndef MARKET_DATA_GENERATOR_H
#define MARKET_DATA_GENERATOR_H

#include "includes.h"
#include "commonStockFactory.h"
#include "preferredStockFactory.h"

/**
 * @class MarketDataGenerator
 * @brief A class responsible for generating simulated market data in a stock trading system.
 *
 * The MarketDataGenerator class simulates market data by generating random stock price changes.
 * It also manages information about available stocks and their prices.
 */
class MarketDataGenerator {
public:
    /**
     * @brief Constructs a MarketDataGenerator object with an optional duration parameter.
     *
     * @param d The duration of the market data simulation in time units (default is 20).
     */
    MarketDataGenerator(int d = 20);

    /**
     * @brief Initiates the simulation of market data generation.
     *
     * This method starts the simulation process, continuously updating stock prices with random changes over time.
     */
    void startSimulation();

    /**
     * @brief Retrieves the current price of a specified stock.
     *
     * @param sym The symbol or identifier of the stock.
     * @return The current price of the specified stock.
     */
    double getStockPrice(const std::string& sym);

    /**
     * @brief Retrieves a vector of shared pointers to all available stocks.
     *
     * @return A vector of shared pointers to Stock objects representing available stocks.
     */
    std::vector<std::shared_ptr<Stock>> getStocks() const;

    /**
     * @brief Loads stock information from a JSON file and initializes the available stocks.
     *
     * @param filename The name of the JSON file containing stock information.
     */
    void loadStockInfoFromJSON(const std::string& filename);

    /**
     * @brief Sets the duration of the market data simulation.
     *
     * @param duration The duration of the simulation in time units.
     */
    void setDuration(int duration);

    /**
     * @brief Retrieves the duration of the market data simulation.
     *
     * @return The duration of the simulation in time units.
     */
    int getDuration() const;

private:
    /**
     * @brief Generates a random price change for a stock based on its current price.
     *
     * @param currentPrice The current price of the stock.
     * @return The random price change to apply to the stock.
     */
    double generateRandomPriceChange(double currentPrice);

private:
    std::vector<std::shared_ptr<Stock>> stocks; ///< Vector of available stocks.
    int duration; ///< Duration of the market data simulation in time units.
};

#endif // MARKET_DATA_GENERATOR_H
