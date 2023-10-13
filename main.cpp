#include "include/tradingPlatform.h"
#include "include/platformInitializer.h"
#include "include/signalhandler.h"

int main() {
    TradingPlatform tr(OrderBook::getInstance());   
    SignalHandler signalHandler(&tr);
    SignalHandler::setInstance(&signalHandler);
    std::signal(SIGINT, SignalHandler::signalHandler);
    std::signal(SIGTERM, SignalHandler::signalHandler);
    std::signal(SIGABRT, SignalHandler::signalHandler);
    PlatformInitializer init(tr);
    tr.startTradingSimulation();
}
