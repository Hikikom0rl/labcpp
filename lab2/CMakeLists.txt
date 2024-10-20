cmake_minimum_required(VERSION 3.28)
project(lab4)
enable_testing()
#target_include_directories(iomanip INTERFACE include)

add_executable(main main.cpp)

#file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/gprotect.cpp "#include <iomanip.hpp>\n")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory(tests)


#file(GLOB TESTS tests/*.cpp)
