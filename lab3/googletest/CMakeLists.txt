include(AddGtest)

add_executable(google_tests googletest.cpp)

target_link_libraries(google_tests PUBLIC diff gtest gtest_main)
