#include "../include/preferredStockFactory.h"

std::shared_ptr<Stock> PreferredStockFactory::createStock(const std::string& symbol, double price, int volume, double dividend) {
    return std::make_shared<PreferredStock>(symbol, dividend, price, volume);
}
