cmake_minimum_required(VERSION 3.26)
project(holaLuna)

set(CMAKE_CXX_STANDARD 17)

add_executable(holaLuna main.cpp)
find_package(box2d CONFIG REQUIRED)
target_link_libraries(holaLuna PRIVATE box2d::box2d)
