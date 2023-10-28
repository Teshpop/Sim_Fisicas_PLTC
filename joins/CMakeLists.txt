cmake_minimum_required(VERSION 3.26)
project(joins)

set(CMAKE_CXX_STANDARD 17)

add_executable(joins main.cpp
        ref.h
        Dist.cpp
        Gear.cpp
        Revolute.cpp)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(joins PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(joins PRIVATE box2d::box2d)