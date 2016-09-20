set(SOURCE_FILES main.cpp Fit.cpp Fit.h)
add_executable(Fit ${SOURCE_FILES})

include_directories(Fit ../Helpers)

target_link_libraries(Fit Fit)