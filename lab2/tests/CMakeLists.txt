include(AddCatch2)
add_executable(iomaniptests iomanip.cpp)
target_link_libraries(iomaniptests PUBLIC Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(iomaniptests)
