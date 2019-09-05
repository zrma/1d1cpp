cmake_minimum_required(VERSION 3.10)
project(src)

set(SOURCE_FILES main.cpp pch.h type_traits.h
        hacker_rank/introduction.cpp hacker_rank/introduction.h
        hacker_rank/strings.cpp hacker_rank/strings.h
        hacker_rank/structs.cpp hacker_rank/structs.h)
add_executable(1d1cpp ${SOURCE_FILES})

set(Boost_USE_STATIC_LIBS OFF) # enable dynamic linking
set(Boost_USE_MULTITHREAD ON)  # enable multithreading

find_package(Boost)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif (Boost_FOUND)

find_package(Boost REQUIRED COMPONENTS)

target_link_libraries(1d1cpp LINK_PUBLIC ${Boost_LIBRARIES})