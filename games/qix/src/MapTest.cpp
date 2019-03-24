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
		explicit MapTest() : Map(0, 0)
		{}

		void SetUp(int width, int height)
		{
			static_cast<Map &>(*this) = Map(width, height);
		}
	};

	TEST_F(MapTest, size)
	{
		SetUp(10, 10);
		ASSERT_EQ(_width, 10);
		ASSERT_EQ(_height, 10);
		ASSERT_EQ(_cells.size(), 100);
	}
}
