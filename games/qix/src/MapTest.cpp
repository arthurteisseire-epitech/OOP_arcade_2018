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
		MapTest() : Map(0, 0) {}
		void SetUp(int width, int height)
		{
			_width = width;
			_height = height;
		}
	};

	TEST_F(MapTest, size)
	{
		SetUp(10, 10);
		ASSERT_EQ(_width, 10);
		ASSERT_EQ(_height, 10);
	}
}
