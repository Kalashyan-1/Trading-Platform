#include "../include/commonStock.h"

CommonStock::CommonStock(const std::string& sym, double lastDiv, double pr, int trVol) 
    : symbol{sym}, lastDividend{lastDiv}, price{pr},  tradingVolume{trVol} {}


double CommonStock::getPrice() const {
    return price;
}

int CommonStock::getTradingVolume() const {
    return tradingVolume;
}

void CommonStock::setTradingVolume(int vol) {
    tradingVolume = vol;
}

void CommonStock::setPrice(double newP) {
    price = newP;
}

std::string CommonStock::getSymbol() const {
    return symbol;
}
