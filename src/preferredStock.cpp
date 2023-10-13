#include "../include/preferredStock.h"

PreferredStock::PreferredStock(const std::string& sym, double fixedDiv, double pr, int trVol) 
    : symbol{sym}, fixedDividend{fixedDiv}, price{pr}, tradingVolume{trVol} {}


double PreferredStock::getPrice() const {
    return price;
}

int PreferredStock::getTradingVolume() const {
    return tradingVolume;
}

void PreferredStock::setTradingVolume(int vol) {
    tradingVolume = vol;
}

void PreferredStock::setPrice(double newP) {
    price = newP;
}

std::string PreferredStock::getSymbol() const {
    return symbol;
}
