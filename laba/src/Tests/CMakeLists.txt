add_subdirectory(/usr/src/gtest [binary_dir])
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
#include(GoogleTest)
add_executable(Tests
        ArraySequenceTests.cpp)
target_link_libraries(Tests gtest gtest_main)