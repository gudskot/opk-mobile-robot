include(GoogleTest)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(lidarTest
    test_lidar.cpp
)

target_link_libraries(lidarTest
    ${OpenCV_LIBS}
    GTest::gtest
    GTest::gtest_main
)

target_include_directories(lidarTest PRIVATE ../inc/)