CMAKE_MINIMUM_REQUIRED(VERSION 3.25.0)

project(
    lab_algorithms
    VERSION 0.2.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./algorithms/sources)
include_directories(./algorithms/headers)
include_directories(./tests/sources)
include_directories(./tests/headers)
include_directories(./headers)

# Algorithms
set(ALGORITHMS_SRC algorithms/sources/algorithms.cpp)
set(ALGORITHMS_HDR algorithms/headers/algorithms.hpp)
add_library(algs_lib ${ALGORITHMS_SRC} ${ALGORITHMS_HDR})

# Tests
set(TESTS_SRC tests/sources/tests.cpp)
set(TESTS_HDR tests/headers/tests.hpp)
add_library(tests_lib ${TESTS_SRC} ${TESTS_HDR})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} algs_lib)
target_link_libraries(${PROJECT_NAME} tests_lib)
