cmake_minimum_required(VERSION 3.5)

project(j20 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(j20 OBJECT src/json.hpp src/json.cpp)
target_include_directories(j20 INTERFACE src)

add_executable(j20_example example/main.cpp)
target_link_libraries(j20_example PRIVATE j20)

add_executable(j20_tests
    tests/common.hpp
    tests/main.cpp
    tests/test_semantics_construct.cpp
    tests/test_semantics_convert.cpp
    tests/test_semantics_destruct.cpp
    tests/test_semantics_asign.cpp
    tests/test_text_dumps.cpp
    tests/test_text_loads.cpp
    tests/test_text_readerror.cpp
    tests/test_value_is.cpp
    tests/test_value_get_if.cpp
    tests/test_value_get.cpp
    tests/test_value_visit.cpp
    tests/test_value_emplace.cpp
    tests/test_value_at.cpp
    tests/test_value_index.cpp
    tests/test_value_equal.cpp
    tests/test_value_compare.cpp
    tests/test_value_negate.cpp
    )
target_link_libraries(j20_tests PRIVATE j20)
target_include_directories(j20_tests PRIVATE 3rdparty)

include(CTest)
include(3rdparty/Catch.cmake)
catch_discover_tests(j20_tests)

