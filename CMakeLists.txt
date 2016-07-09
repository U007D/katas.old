cmake_minimum_required(VERSION 3.5)
project(App)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

set(SOURCE_FILES main.cpp App/HelloWorld.cpp App/HelloWorld.h)
add_executable(runApp ${SOURCE_FILES})

include_directories(App)

add_subdirectory(App)
add_subdirectory(Tests)

target_link_libraries(runApp App)