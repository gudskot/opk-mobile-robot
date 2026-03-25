cmake_minimum_required(VERSION 3.10)
project(cv4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenCV REQUIRED)

add_subdirectory(tests)

add_executable(main
    src/Canvas.cpp
    src/Environment.cpp
    src/Lidar.cpp
    main.cpp
)

target_link_libraries(main PRIVATE ${OpenCV_LIBS})
target_include_directories(main PRIVATE inc/)