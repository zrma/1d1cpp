set(SOURCE_FILES
        main.cpp
        pch.h
        type_traits.h
        hacker_rank/introduction.cpp hacker_rank/introduction.h
        hacker_rank/strings.cpp hacker_rank/strings.h
        hacker_rank/structs.cpp hacker_rank/structs.h
        hacker_rank/stl.cpp hacker_rank/stl.h)

add_executable(1d1cpp ${SOURCE_FILES})
target_compile_features(1d1cpp PRIVATE cxx_std_17)

find_package(Boost REQUIRED)

if (TARGET Boost::headers)
    target_link_libraries(1d1cpp PRIVATE Boost::headers)
elseif (TARGET Boost::boost)
    target_link_libraries(1d1cpp PRIVATE Boost::boost)
else ()
    target_include_directories(1d1cpp PRIVATE ${Boost_INCLUDE_DIRS})
endif ()
