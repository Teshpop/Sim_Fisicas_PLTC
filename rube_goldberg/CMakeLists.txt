cmake_minimum_required(VERSION 3.26)
project(rube_goldberg)

set(CMAKE_CXX_STANDARD 17)

add_executable(rube_goldberg main.cpp
        ref.h
        Figures.h
        Joins.h)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(rube_goldberg PRIVATE box2d::box2d)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(rube_goldberg PRIVATE sfml-system sfml-network sfml-graphics sfml-window)