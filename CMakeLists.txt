cmake_minimum_required(VERSION 3.0)
project(TradingPlatform)

find_package(nlohmann_json REQUIRED)

set(SOURCES 
    main.cpp
    src/commonStock.cpp
    src/commonStockFactory.cpp
    src/limitOrder.cpp
    src/limitOrderFactory.cpp
    src/marketDataGenerator.cpp
    src/marketOrder.cpp
    src/marketOrderfactory.cpp
    src/orderBook.cpp
    src/preferredStock.cpp
    src/preferredStockFactory.cpp
    src/trader.cpp
    src/tradingPlatform.cpp
    src/platformInitializer.cpp
    src/platformPausedState.cpp
    src/signalhandler.cpp
)

add_executable(TradingPlatform ${SOURCES})

target_link_libraries(TradingPlatform PRIVATE nlohmann_json::nlohmann_json)
