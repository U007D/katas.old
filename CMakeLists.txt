cmake_minimum_required(VERSION 3.5)
project(App)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

set(SOURCE_FILES main.cpp)
add_executable(runApp ${SOURCE_FILES})

include_directories(App)
include_directories(lib/Utils)
include_directories(lib/range-v3/include)

add_subdirectory(App)
add_subdirectory(lib/Utils)
add_subdirectory(lib/range-v3)
add_subdirectory(Tests)

target_link_libraries(runApp App Utils)