include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Tests/3rdParty/Catch/include ${CMAKE_CURRENT_SOURCE_DIR}/Modules/BowlingGame ${CMAKE_CURRENT_SOURCE_DIR}/Modules/3rdParty/range/include/ ${CMAKE_CURRENT_SOURCE_DIR}/Modules/3rdParty/cpp17_headers/include/ ${CMAKE_CURRENT_SOURCE_DIR}/Modules)

add_subdirectory(Modules)
add_subdirectory(Tests)
