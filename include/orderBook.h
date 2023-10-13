#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include "limitOrder.h"
#include "marketOrder.h"

/**
 * @class OrderBook
 * @brief A singleton class representing the order book in a stock trading system.
 *
 * The OrderBook class manages and processes buy and sell orders in a trading system.
 * It implements a singleton pattern to ensure a single instance of the order book.
 */
class OrderBook {
public:
    /**
     * @brief Get the singleton instance of the OrderBook.
     *
     * @return A reference to the singleton OrderBook instance.
     */
    static OrderBook& getInstance();

    /**
     * @brief Process a trading order by adding it to the appropriate buy or sell queue.
     *
     * @param order A shared pointer to the trading order to be processed.
     */
    void processOrder(std::shared_ptr<Order> order);

    /**
     * @brief Get a reference to the list of buy orders in the order book.
     *
     * @return A reference to the list of buy orders.
     */
    std::vector<std::shared_ptr<Order>>& getBuyOrders();

    /**
     * @brief Get a reference to the list of sell orders in the order book.
     *
     * @return A reference to the list of sell orders.
     */
    std::vector<std::shared_ptr<Order>>& getSellOrders();

    /**
     * @brief Get the name of a trader based on their unique ID.
     *
     * @param traderID The unique identifier of the trader.
     * @return The name of the trader associated with the ID.
     */
    std::string getTraderName(int traderID) const;

    /**
     * @brief Serialize the order book's information into JSON format.
     *
     * @return A JSON representation of the order book.
     */
    nlohmann::json serialize() const;

    /**
     * @brief Remove matched orders from the order book.
     *
     * @param ord A vector of shared pointers to orders to be removed.
     * @param str The symbol or identifier of the stock associated with the orders.
     */
    void removeFromOrderBook(std::vector<std::shared_ptr<Order>> ord, const std::string& str);

    /**
     * @brief Overloaded << operator to facilitate printing the order book.
     *
     * @param os The output stream to write the order book information.
     * @param orderBook The OrderBook object to be printed.
     * @return The output stream with the order book information.
     */
    friend std::ostream& operator<<(std::ostream& os, const OrderBook& orderBook);

private:
    /**
     * @brief Private constructor for the OrderBook class (singleton pattern).
     */
    OrderBook() = default;

    // Disallow copy and move operations
    OrderBook(const OrderBook&) = delete;
    OrderBook(OrderBook&&) = delete;
    OrderBook& operator=(const OrderBook&) = delete;
    OrderBook& operator=(OrderBook&&) = delete;

private:
    std::vector<std::shared_ptr<Order>> buyOrders; ///< Data structure for buy orders.
    std::vector<std::shared_ptr<Order>> sellOrders; ///< Data structure for sell orders.
    std::unordered_map<std::string, std::pair<int, int>> buySellQuantity; ///< Map to track buy and sell quantities for each stock.
    mutable std::mutex bookMutex; ///< Mutex for thread safety.
    std::unordered_map<int, std::string> traderNames; ///< Map trader IDs to trader names.
};

#endif // ORDER_BOOK_H


