#ifndef PLATFORM_STATE_H
#define PLATFORM_STATE_H

class TradingPlatform;

/**
 * @class PlatformState
 * @brief An abstract class representing the state of a trading platform.
 *
 * The PlatformState class defines an abstract interface for representing the state of a TradingPlatform.
 * Derived classes of PlatformState can be used to capture and manage different states of the platform.
 */
class PlatformState {
public:
    /**
     * @brief Takes the current state of a TradingPlatform and applies it.
     *
     * This pure virtual method is implemented by derived classes to capture the current state of a TradingPlatform
     * and apply it to the platform when needed.
     *
     * @param platform A reference to the TradingPlatform whose state is to be taken and applied.
     */
    virtual void takeCurrentState(TradingPlatform& platform) = 0;
};

#endif // PLATFORM_STATE_H

