project(unit_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB TEST_SOURCES *.cpp *.cc *.c)

add_executable(${PROJECT_NAME} ${TEST_SOURCES} ${SOURCES_WITHOUT_MAIN})
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

# Custom target: make run_unit_tests
add_custom_target(run_${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
