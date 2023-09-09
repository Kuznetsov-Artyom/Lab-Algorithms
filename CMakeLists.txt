CMAKE_MINIMUM_REQUIRED(VERSION 3.25.0)

project(
    lab_algorithms
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./sources)
include_directories(./headers)

set(SRC
    sources/tests.cpp
)
set(HDR
    headers/traits.hpp
    headers/timer.hpp
    headers/generator.hpp
    headers/avltree.hpp
    headers/algorithms.hpp
    headers/tests.hpp
)

add_library(main_lib ${SRC} ${HDR})

add_executable(lab_algorithms main.cpp)
target_link_libraries(lab_algorithms main_lib)