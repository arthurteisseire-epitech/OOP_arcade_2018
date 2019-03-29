/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** CellTest.cpp
*/

#include "gtest/gtest.h"
#include "Cell.hpp"

namespace arc {
	class CellTest : public Cell, public ::testing::Test {
	public:
		CellTest() : Cell(WALKABLE)
		{}
	};

	TEST_F(CellTest, state)
	{
		ASSERT_EQ(_state, WALKABLE);
	}
}
