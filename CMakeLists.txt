cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(vega_unit_test)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_compile_definitions("BOOST_ALL_DYN_LINK"
        "$<$<CXX_COMPILER_ID:MSVC>:_CRT_SECURE_NO_WARNINGS>"
        "$<$<CXX_COMPILER_ID:MSVC>:_CRT_NONSTDC_NO_DEPRECATE>")

FIND_PACKAGE(Boost REQUIRED)

add_executable(vega_unit_test main.cpp vega_intrusive_ptr.hpp flightgroup_member.cpp flightgroup_member.hpp unit.cpp unit.hpp universe.hpp vega_unit_collection.hpp can_be_parent.cpp can_be_parent.hpp can_be_owner.cpp can_be_owner.hpp)

target_include_directories(vega_unit_test PRIVATE ${Boost_INCLUDE_DIRS})
