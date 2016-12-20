add_subdirectory(Unit)
add_subdirectory(Integration)
add_subdirectory(Performance)
add_subdirectory(System)

set(SOURCE_FILES Runner.Tests/CatchMain.cpp ${UNIT_TEST_SOURCE_FILES} ${INTEGRATION_TEST_SOURCE_FILES} ${PERFORMANCE_SOURCE_FILES} ${SYSTEM_TEST_SOURCE_FILES})
add_executable(Tests ${SOURCE_FILES})

target_link_libraries (Tests PUBLIC BowlingGame)
