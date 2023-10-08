cmake_minimum_required(VERSION 3.26)
project(Poligonos_)

set(CMAKE_CXX_STANDARD 17)

add_executable(Poligonos_ main.cpp)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(Poligonos_ PRIVATE box2d::box2d)
