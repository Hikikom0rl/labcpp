#include "diff.h"
#include <iostream>
#include <cstdio>
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>


TEST_CASE("Diff are computed","[diffsqrEq]"){
	REQUIRE(diff(sin,0,0.01)==Catch::Approx(1).margin(0.01));
	REQUIRE(diff(sqrt,1,0.1)== Catch::Approx(0.5).margin(0.1));
        REQUIRE(diff(tan,M_PI,0.01)== Catch::Approx(1).margin(0.01));
        REQUIRE(diff(asin,0,0.01)== Catch::Approx(1).margin(0.01));
}
