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
	body_t cp = _body_positions;

	eat();
	EXPECT_EQ(length + 1, _body_positions.size());
	EXPECT_EQ(abs((int)(cp.back().first - _body_positions.back().first)), 1);
	EXPECT_EQ(cp.back().second, _body_positions.back().second);
}

TEST_F(SnakeTest, FindTailDirection)
{
	_body_positions.push_back(pos_t(0, 2));
	_body_positions.push_back(pos_t(0, 3));
	EXPECT_EQ(find_tail_direction(), pos_t(0, -1));

	_body_positions.push_back(pos_t(0, 3));
	_body_positions.push_back(pos_t(0, 2));
	EXPECT_EQ(find_tail_direction(), pos_t(0, 1));

	_body_positions.push_back(pos_t(2, 0));
	_body_positions.push_back(pos_t(3, 0));
	EXPECT_EQ(find_tail_direction(), pos_t(-1, 0));

	_body_positions.push_back(pos_t(3, 0));
	_body_positions.push_back(pos_t(2, 0));
	EXPECT_EQ(find_tail_direction(), pos_t(1, 0));
}

//TEST_F(SnakeTest, Move)
//{
//	std::list<std::pair<unsigned int, unsigned int>> pos_list = _;
//}
