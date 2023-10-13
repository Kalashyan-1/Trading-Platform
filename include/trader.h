#ifndef TRADER_H
#define TRADER_H

#include "marketDataGenerator.h"
#include "marketOrderFactory.h"
#include "limitOrderFactory.h"
#include "orderBook.h"

/**
 * @class Trader
 * @brief Represents a trader participating in the stock trading platform.
 *
 * The Trader class models a trader who can buy and sell stocks within the trading platform.
 */
class Trader {
public:
    /**
     * @brief Constructs a Trader object with a specified name, initial balance, and identifier.
     *
     * @param n The name of the trader.
     * @param initialBalance The initial balance of the trader's account.
     * @param Id The unique identifier for the trader.
     */
    Trader(const std::string& n, double initialBalance, int Id);

    /**
     * @brief Performs a buy order for a specified quantity of a stock symbol.
     *
     * @param dataGenerator A reference to the MarketDataGenerator object.
     * @param book A reference to the OrderBook object.
     * @param symbol The symbol of the stock to buy.
     * @param quantity The quantity of the stock to buy.
     */
    void buy(MarketDataGenerator& dataGenerator, OrderBook& book, const std::string& symbol, int quantity);

    /**
     * @brief Performs a sell order for a specified quantity of a stock symbol.
     *
     * @param dataGenerator A reference to the MarketDataGenerator object.
     * @param book A reference to the OrderBook object.
     * @param symbol The symbol of the stock to sell.
     * @param quantity The quantity of the stock to sell.
     */
    void sell(MarketDataGenerator& dataGenerator, OrderBook& book, const std::string& symbol, int quantity);

    /**
     * @brief Makes a market strategy decision based on order type, stock symbol, quantity, and current price.
     *
     * @param type The order type (Buy Order or Sell Order).
     * @param symbol The symbol of the stock.
     * @param quantity The quantity of the stock.
     * @param currentPrice The current price of the stock.
     * @return A shared pointer to the created Order object.
     */
    std::shared_ptr<Order> marketStrategyDecision(OrderType type, const std::string& symbol, int quantity, double currentPrice);

    /**
     * @brief Checks if the trader's portfolio is empty.
     *
     * @return True if the portfolio is empty; false otherwise.
     */
    bool isPortfolioEmpty();

    /**
     * @brief Updates the trader's balance based on transactions.
     *
     * @param amount The amount to add or subtract from the balance.
     */
    void updateBalance(double amount);

    /**
     * @brief Retrieves the current balance of the trader.
     *
     * @return The current balance.
     */
    double getBalance() const;

    /**
     * @brief Retrieves the name of the trader.
     *
     * @return The name of the trader.
     */
    std::string getName() const;

    /**
     * @brief Serializes the trader's information into JSON format.
     *
     * @return A JSON representation of the trader.
     */
    nlohmann::json serialize() const;

    /**
     * @brief Retrieves the stock symbol and volume from the trader's portfolio.
     *
     * @return A pair containing the stock symbol and its corresponding volume.
     */
    std::pair<std::string, int> getStockVolumeFromPortfolio();

    /**
     * @brief Overloaded stream output operator to print trader information.
     *
     * @param os The output stream.
     * @param trader The Trader object to be printed.
     * @return The output stream with the trader information.
     */
    friend std::ostream& operator<<(std::ostream& os, const Trader& trader);

private:
    int id;
    double balance;
    std::string name;
    std::unordered_map<std::string, int> portfolio; ///< Stores the quantity of each stock in the trader's portfolio.
};

#endif // TRADER_H


