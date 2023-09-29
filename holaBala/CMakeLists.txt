cmake_minimum_required(VERSION 3.26)
project(holaBala)

set(CMAKE_CXX_STANDARD 17)

add_executable(holaBala main.cpp)
find_package(box2d CONFIG REQUIRED)
target_link_libraries(holaBala PRIVATE box2d::box2d)
