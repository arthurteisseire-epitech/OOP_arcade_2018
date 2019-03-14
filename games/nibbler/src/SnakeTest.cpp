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
	SnakeTest() : Snake(init_pos, 4) {};

protected:
	static const std::pair<unsigned int, unsigned int> init_pos;
	static const std::pair<unsigned int, unsigned int> move;
};

const std::pair<unsigned int, unsigned int> SnakeTest::init_pos = {1, 2};

TEST_F(SnakeTest, Init)
{
	EXPECT_EQ(_body_positions.size(), 4);
	EXPECT_EQ(_body_positions[0], init_pos);
	EXPECT_EQ(_body_positions[1].first, init_pos.first + 1);
	EXPECT_EQ(_body_positions[1].second, init_pos.second);
	EXPECT_EQ(_body_positions[2].first, init_pos.first + 2);
	EXPECT_EQ(_body_positions[2].second, init_pos.second);
	EXPECT_EQ(_body_positions[3].first, init_pos.first + 3);
	EXPECT_EQ(_body_positions[3].second, init_pos.second);
}

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
