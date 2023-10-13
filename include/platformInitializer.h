#ifndef PLATFORM_INITIALIZER_H
#define PLATFORM_INITIALIZER_H

#include "tradingPlatform.h"

/**
 * @class PlatformInitializer
 * @brief A class responsible for initializing a trading platform with orders and configurations.
 *
 * The PlatformInitializer class is responsible for setting up a TradingPlatform by providing it with initial
 * orders and configurations. It offers methods to initialize the platform through command-line or file-based
 * configurations.
 */
class PlatformInitializer {
public:
    /**
     * @brief Constructs a PlatformInitializer object and associates it with a TradingPlatform.
     *
     * @param platform A reference to the TradingPlatform to be initialized.
     */
    PlatformInitializer(TradingPlatform& platform);

private:
    /**
     * @brief Initializes the trading platform using command-line configurations.
     *
     * This method allows the user to interactively provide initial orders and configurations for the trading platform.
     *
     * @param platform A reference to the TradingPlatform to be initialized.
     */
    void commandLineInit(TradingPlatform& platform);

    /**
     * @brief Initializes the trading platform using file-based configurations.
     *
     * This method loads initial orders and configurations from a JSON file and applies them to the trading platform.
     *
     * @param platform A reference to the TradingPlatform to be initialized.
     */
    void fileInit(TradingPlatform& platform);

    /**
     * @brief Initializes a collection of orders from a JSON object and associates them with the specified strategy and type.
     *
     * @param ordersJson A JSON object containing order information.
     * @param orders A vector of shared pointers to orders to be initialized.
     * @param orderStrategy The order strategy (LIMIT or MARKET) for the initialized orders.
     * @param orderType The order type (BUY or SELL) for the initialized orders.
     */
    void initializeOrdersFromJSON(const nlohmann::json& ordersJson, std::vector<std::shared_ptr<Order>>& orders, OrderStrategy orderStrategy,  OrderType orderType);
};

#endif // PLATFORM_INITIALIZER_H


