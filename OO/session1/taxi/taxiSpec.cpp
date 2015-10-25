#include "gtest/gtest.h"

#include "taxi.h"

TEST(TaxiSpec, ShouldReturnCorrectChagreWhenGivenAnSepcifyDistance)
{
	ASSERT_EQ(1, chargeTaxiFee(1));
}
