#include "gtest/gtest.h"

TEST(TestLength, ShouldEqualWhenTwoLengthHaveSameValueAndUnit)
{
	ASSERT_TRUE( Length(10.5, "m") == Length(10.5, "m"));
}


