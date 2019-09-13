cmake_minimum_required(VERSION 3.9)
project(1d1cpp)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif (MSVC)

add_subdirectory(src)
add_subdirectory(test)
