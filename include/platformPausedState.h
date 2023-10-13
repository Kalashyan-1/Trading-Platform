#ifndef PLATFORM_PAUSED_STATE_H
#define PLATFORM_PAUSED_STATE_H

#include "tradingPlatform.h"

/**
 * @class PlatformPausedState
 * @brief A class representing the paused state of a trading platform.
 *
 * The PlatformPausedState class captures and manages the paused state of a TradingPlatform.
 * It stores information about trader balances and stock prices while the platform is paused.
 */
class PlatformPausedState : public PlatformState {
public:
    /**
     * @brief Constructs a PlatformPausedState object associated with a TradingPlatform.
     *
     * @param platform A reference to the TradingPlatform in the paused state.
     */
    PlatformPausedState(TradingPlatform& platform);

    /**
     * @brief Takes the current state of a TradingPlatform and applies it.
     *
     * This method captures the trader balances and stock prices in the paused state and stores them for reference.
     * It implements the abstract method defined in the PlatformState base class.
     *
     * @param platform A reference to the TradingPlatform whose paused state is to be taken.
     */
    void takeCurrentState(TradingPlatform& platform) override;

    /**
     * @brief Virtual destructor for the PlatformPausedState class.
     */
    virtual ~PlatformPausedState() {}

private:
    /**
     * @brief Prints the captured current state of the TradingPlatform.
     *
     * This method prints the trader balances and stock prices captured in the paused state.
     *
     * @param platform A reference to the TradingPlatform for which the state is to be printed.
     */
    void printCurrentState(TradingPlatform& platform);

private:
    std::unordered_map<std::string, double> traderBalance; ///< Map of trader balances in the paused state.
    std::unordered_map<std::string, double> stockPrice; ///< Map of stock prices in the paused state.
};

#endif // PLATFORM_PAUSED_STATE_H

