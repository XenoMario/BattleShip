#include <gtest/gtest.h>
#include "Ship.h"

TEST(SHIP_TESTS, given_emptySize_when_setSize_then_sizeIsAdded)
{
	Battleships::Ship SS;
	SS.setSize(10);

	EXPECT_EQ(10, SS.Size());
}