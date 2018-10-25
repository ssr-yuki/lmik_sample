cmake_minimum_required(VERSION 2.8)
project(lmik_sample)

add_definitions(-std=c++11)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_library(LMIK
    ${PROJECT_SOURCE_DIR}/src/lmik.cpp
)

add_executable(test src/test.cpp)

target_link_libraries(test LMIK)
