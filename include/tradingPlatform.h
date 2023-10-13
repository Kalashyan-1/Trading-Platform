#ifndef TRADING_PLATFORM_H
#define TRADING_PLATFORM_H

#include "trader.h"
#include "platformState.h"

/**
 * @class TradingPlatform
 * @brief A class representing a stock trading platform.
 *
 * The TradingPlatform class simulates a stock trading system where multiple traders can buy and sell stocks.
 * It manages trading activities and provides control over the simulation.
 */

class TradingPlatform {
public:
    /**
     * @brief Constructs a TradingPlatform object.
     *
     * @param orderBook A reference to the OrderBook object that represents the trading order book.
     */
    TradingPlatform(OrderBook& orderBook);

    /**
     * @brief Destroys the TradingPlatform object and releases associated resources.
     */
    ~TradingPlatform();

    /**
     * @brief Starts the trading simulation on the platform.
     */
    void startTradingSimulation();

    /**
     * @brief Serializes the current state of the trading platform into JSON format.
     *
     * @return A JSON representation of the platform's state.
     */
    nlohmann::json serialize() const;

    /**
     * @brief Retrieves a vector of shared pointers to Stock objects available on the platform.
     *
     * @return A vector of shared pointers to Stock objects.
     */
    std::vector<std::shared_ptr<Stock>> getStocks() const;

    /**
     * @brief Retrieves the vector of Trader objects participating in the platform.
     *
     * @return A reference to the vector of Trader objects.
     */
    std::vector<Trader>& getTraders();

    /**
     * @brief Retrieves a reference to the OrderBook object representing the trading order book.
     *
     * @return A reference to the OrderBook object.
     */
    OrderBook& getOrderBook();

    /**
     * @brief Sets the duration of the trading simulation in seconds.
     *
     * @param d The duration of the simulation.
     */
    void setDuration(int d);

    /**
     * @brief Resumes trading threads that may have been paused.
     */
    void resumeThreads();

    /**
     * @brief Pauses trading threads to temporarily halt the simulation.
     */
    void pauseThreads();

    /**
     * @brief Stops all trading threads and terminates the platform.
     */
    void stopThread();

    /**
     * @brief Saves the current state of the platform.
     */
    void saveState();

private:
    /**
     * @brief Main simulation loop for the trading platform.
     */
    void simulationLoop();

    /**
     * @brief Worker thread function for handling trader actions concurrently.
     */
    void workerThreadFunction();

    /**
     * @brief Handles actions performed by individual traders.
     *
     * @param trader The trader for which actions should be handled.
     */
    void handleTraderActions(Trader& trader);

private:
    std::vector<Trader> traders; 
    OrderBook& orderBook;        
    MarketDataGenerator dataGenerator; 

    // Thread pool for trader actions
    std::vector<std::thread> workerThreads; 
    std::queue<std::function<void()>> taskQueue; 
    std::mutex taskQueueMutex; 
    std::condition_variable taskAvailable; 

    std::unique_ptr<PlatformState> state; 
    std::atomic<bool> pause;
    std::mutex pauseMutex;
    std::condition_variable pauseCondition;

    std::atomic<bool> stopThreads;
};

#endif // TRADING_PLATFORM_H


