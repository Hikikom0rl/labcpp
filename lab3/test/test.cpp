#include "diff.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <catch2/catch_test_macros.hpp>


TEST_CASE("Diff are computed","[diffsqrEq]"){
	REQUIRE(std::to_string(diffsqrEq(0,0,5,0.01,4))=="0.000000");
	REQUIRE(std::to_string(diffsqrEq(1,1,1,0.1,5))== "11.010000");
        REQUIRE(std::to_string(diffsqrEq(1,0,0,0.01,1))== "2.001000");
        REQUIRE(std::to_string(diffsqrEq(2,5,6,0.01,10))== "45.002000");
}
