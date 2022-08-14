cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(vega_unit_test)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_compile_definitions("BOOST_ALL_DYN_LINK" "$<$<CXX_COMPILER_ID:MSVC>:__x86_64__>" "$<$<CXX_COMPILER_ID:MSVC>:_CRT_SECURE_NO_WARNINGS>" "$<$<CXX_COMPILER_ID:MSVC>:_CRT_NONSTDC_NO_DEPRECATE>")

FIND_PACKAGE(Boost REQUIRED COMPONENTS)

add_executable(vega_unit_test main.cpp)

target_include_directories(vega_unit_test PRIVATE ${Boost_INCLUDE_DIRS})
