#ifndef SIGNALHANDLER_H_
#define SIGNALHANDLER_H_

#include "tradingPlatform.h"

/**
 * @class SignalHandler
 * @brief A class responsible for handling signals in the context of a trading platform.
 *
 * The SignalHandler class manages signal handling for a TradingPlatform by registering signal handlers and
 * responding to specific signals as needed.
 */
class SignalHandler {
public:
    /**
     * @brief Constructs a SignalHandler object associated with a TradingPlatform.
     *
     * @param tr A pointer to the TradingPlatform for which signal handling is managed.
     */
    SignalHandler(TradingPlatform* tr);

    /**
     * @brief Static method to handle signals.
     *
     * This static method is registered as the signal handler for specific signals and is responsible for responding
     * to those signals when they occur.
     *
     * @param signum The signal number indicating the type of signal received.
     */
    static void signalHandler(int signum);

    /**
     * @brief Static method to set the instance of SignalHandler.
     *
     * This method allows setting the instance of SignalHandler for managing signal handling.
     *
     * @param handler A pointer to the SignalHandler instance to be set as the active handler.
     */
    static void setInstance(SignalHandler* handler);

private:
    TradingPlatform* tr; ///< A pointer to the TradingPlatform associated with the signal handler.
    static SignalHandler* instance; ///< Static instance of the SignalHandler for signal management.
};

#endif // SIGNALHANDLER_H_



