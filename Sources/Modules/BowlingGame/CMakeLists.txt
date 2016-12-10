set(SOURCE_FILES BowlingGame.cpp BowlingGame.h)
add_library(BowlingGame ${SOURCE_FILES})

target_include_directories(BowlingGame
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/cpp17_headers/include/
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/range/include/)