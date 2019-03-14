/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SnakeTest.cpp,
*/

#include <list>
#include "Snake.hpp"
#include "gtest/gtest.h"

class SnakeTest : public ::testing::Test, public arc::Snake {
public:
	SnakeTest() : Snake({1, 2}, 4) {};
};

TEST_F(SnakeTest, Eat)
{
	unsigned long length = _body_positions.size();

	eat();
	EXPECT_EQ(length + 1, _body_positions.size());
}

//TEST_F(SnakeTest, Move)
//{
//	std::list<std::pair<unsigned int, unsigned int>> pos_list = _;
//}
