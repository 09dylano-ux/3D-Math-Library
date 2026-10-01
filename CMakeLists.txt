cmake_minimum_required(VERSION 3.20)
project(Custom3DMathLibrary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

enable_testing()

add_executable(MathTests tests/test_math.cpp)
add_test(NAME RunMathTests COMMAND MathTests)
