#include "../include/signalhandler.h"

SignalHandler* SignalHandler::instance = nullptr;

SignalHandler::SignalHandler(TradingPlatform* trd) : tr{trd} {}

void SignalHandler::signalHandler(int signum) {
    if (instance && instance->tr) {
        instance->tr->saveState();
    } 
    exit(signum);
}

void SignalHandler::setInstance(SignalHandler* handler) {
    instance = handler;
}
