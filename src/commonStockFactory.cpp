#include "../include/commonStockFactory.h"


std::shared_ptr<Stock> CommonStockFactory::createStock(const std::string& symbol, double price, int volume, double dividend) {
   return std::make_shared<CommonStock>(symbol, dividend, price, volume);
}
