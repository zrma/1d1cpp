project(test)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run
        main_test.cpp
        hacker_rank/introduction_test.cpp
        hacker_rank/strings_test.cpp
        hacker_rank/structs_test.cpp
        ../src/hacker_rank/introduction.cpp
        ../src/hacker_rank/strings.cpp
        ../src/hacker_rank/structs.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)
