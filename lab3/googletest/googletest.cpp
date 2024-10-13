#include "diff.h"
#include <gtest/gtest.h>

TEST(Difftest,cos){
	EXPECT_NEAR(diff(cos,M_PI/2,0.01),-1.,0.01);
}
TEST(Difftest,sqrt){
        EXPECT_NEAR(diff(sqrt,4,0.01),0.25,0.01);
}
TEST(Difftest,asin){
        EXPECT_NEAR(diff(asin,0,0.01),1,0.01);
}
TEST(Difftest,sin){
        EXPECT_NEAR(diff(sin,M_PI,0.1),-1,0.1);
}
TEST(Difftest,tan){
        EXPECT_NEAR(diff(tan,M_PI,0.01),1,0.01);
}
TEST(Difftest,log){
        EXPECT_NEAR(diff(log,2,0.01),0.5,0.01);
}

