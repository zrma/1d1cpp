add_subdirectory(lib)

add_executable(Google_Tests_run
        main_test.cpp
        hacker_rank/introduction_test.cpp
        hacker_rank/strings_test.cpp
        hacker_rank/structs_test.cpp
        ../src/hacker_rank/introduction.cpp
        ../src/hacker_rank/strings.cpp
        ../src/hacker_rank/structs.cpp
        ../src/hacker_rank/stl.cpp
        hacker_rank/stl_test.cpp)

target_compile_features(Google_Tests_run PRIVATE cxx_std_17)
target_link_libraries(Google_Tests_run PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(Google_Tests_run)
