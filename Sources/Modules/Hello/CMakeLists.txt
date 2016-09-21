set(SOURCE_FILES Hello.cpp Hello.h)
add_library(HelloLib ${SOURCE_FILES})

target_include_directories(HelloLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)