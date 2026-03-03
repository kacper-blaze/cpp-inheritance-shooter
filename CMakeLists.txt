cmake_minimum_required(VERSION 3.19)
project(InheritanceGame)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest /Wall /WX")
    endif()
else()
    set(CMAKE_CXX_FLAGS "--std=c++${CMAKE_CXX_STANDARD} -Wall -Wextra")
    set(COMPILER_DEBUG_FLAGS "-D_DEBUG")
    set(COMPILER_RELEASE_FLAGS "-O3 -DNDEBUG")
    set(LINKER_FLAGS "--std=c++${CMAKE_CXX_STANDARD}")
endif()

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(MAIN_PROJECT_NAME "${PROJECT_NAME}")
set(PROJECT_BINARY_PATH "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}")

file(GLOB SOURCES *.cpp *.cc *.c)
file(GLOB HEADERS *.h *.hpp)
set(SOURCES_WITHOUT_MAIN ${SOURCES})
list(REMOVE_ITEM SOURCES_WITHOUT_MAIN ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

# Add executable with main
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

# Custom target: make run
add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Add subdirectories
add_subdirectory(unit_tests)
add_subdirectory(game)
