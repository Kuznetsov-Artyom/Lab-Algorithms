CMAKE_MINIMUM_REQUIRED(VERSION 3.25.0)

project(lab_algorithms)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./headers)
include_directories(./sources)

add_executable(lab_algorithms main.cpp)
