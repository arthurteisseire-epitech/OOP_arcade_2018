/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MapTest.cpp
*/

#include "gtest/gtest.h"
#include "Map.hpp"

namespace arc {
	class MapTest : public Map, public ::testing::Test {
	public:
		explicit MapTest() : Map({10, 10})
		{}
	};

	TEST_F(MapTest, size)
	{
		ASSERT_EQ(_dimension.x, 10);
		ASSERT_EQ(_dimension.y, 10);
		ASSERT_EQ(static_cast<int>(_cells.size()), 10);
		ASSERT_EQ(static_cast<int>(_cells[0].size()), 10);
	}

	TEST_F(MapTest, in)
	{
		ASSERT_TRUE(in(Position(0, 0)));
		ASSERT_TRUE(in(Position(9, 9)));
	}

	TEST_F(MapTest, out)
	{
		ASSERT_FALSE(in(Position(-1, 0)));
		ASSERT_FALSE(in(Position(0, -1)));
		ASSERT_FALSE(in(Position(-1, -1)));
		ASSERT_FALSE(in(Position(10, 0)));
		ASSERT_FALSE(in(Position(0, 10)));
	}

	TEST_F(MapTest, border)
	{
		ASSERT_EQ(_cells[1][1].state(), Cell::WALKABLE);
		ASSERT_EQ(_cells[0][0].state(), Cell::BORDER);
		ASSERT_EQ(_cells[9][9].state(), Cell::BORDER);
		ASSERT_EQ(_cells[8][0].state(), Cell::BORDER);
		ASSERT_EQ(_cells[0][8].state(), Cell::BORDER);
	}
}
