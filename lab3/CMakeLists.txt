cmake_minimum_required(VERSION 3.20)
project(diff)
enable_testing()
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDART 23)
set(CMAKE_CXX_STANDART_REQUIRED ON)

add_subdirectory(src)


add_executable(main main.cpp)
target_link_libraries(main PRIVATE diff)

add_subdirectory(test)
