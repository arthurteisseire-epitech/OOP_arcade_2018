/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SnakeTest.cpp
*/

#include <list>
#include "Snake.hpp"
#include "gtest/gtest.h"

class SnakeTest : public ::testing::Test, public arc::Snake {
public:
	SnakeTest() : Snake(init_pos, 4, {30, 30})
	{};

protected:
	static const pos_t init_pos;
	static const pos_t move;

	void test_move(Snake &snake, Direction direction, pos_t expected_head);
};

const pos_t SnakeTest::init_pos = {1, 2};

TEST_F(SnakeTest, Init)
{
	EXPECT_EQ(_bodyPositions.size(), (size_t)4);
	EXPECT_EQ(_bodyPositions[0], init_pos);
	EXPECT_EQ(_bodyPositions[1].first, init_pos.first + 1);
	EXPECT_EQ(_bodyPositions[1].second, init_pos.second);
	EXPECT_EQ(_bodyPositions[2].first, init_pos.first + 2);
	EXPECT_EQ(_bodyPositions[2].second, init_pos.second);
	EXPECT_EQ(_bodyPositions[3].first, init_pos.first + 3);
	EXPECT_EQ(_bodyPositions[3].second, init_pos.second);
}

TEST_F(SnakeTest, Eat)
{
	unsigned long length = _bodyPositions.size();
	body_t cp = _bodyPositions;

	eat();
	EXPECT_EQ(length + 1, _bodyPositions.size());
	EXPECT_EQ(abs((int)(cp.back().first - _bodyPositions.back().first)), 1);
	EXPECT_EQ(cp.back().second, _bodyPositions.back().second);
}

TEST_F(SnakeTest, FindTailDirection)
{
	_bodyPositions.push_back(pos_t(0, 2));
	_bodyPositions.push_back(pos_t(0, 3));
	EXPECT_EQ(findTailDirection(), pos_t(0, -1));

	_bodyPositions.push_back(pos_t(0, 3));
	_bodyPositions.push_back(pos_t(0, 2));
	EXPECT_EQ(findTailDirection(), pos_t(0, 1));

	_bodyPositions.push_back(pos_t(2, 0));
	_bodyPositions.push_back(pos_t(3, 0));
	EXPECT_EQ(findTailDirection(), pos_t(-1, 0));

	_bodyPositions.push_back(pos_t(3, 0));
	_bodyPositions.push_back(pos_t(2, 0));
	EXPECT_EQ(findTailDirection(), pos_t(1, 0));
}

void SnakeTest::test_move(Snake &snake, Direction direction, pos_t expected_head)
{
	body_t pos_list = _bodyPositions;

	snake.moveBody(direction);
	EXPECT_EQ(_bodyPositions.front(), expected_head);
	pos_list.pop_back();
	for (size_t i = 0; i < pos_list.size(); ++i)
		EXPECT_EQ(pos_list[i], _bodyPositions[i + 1]);
}

TEST_F(SnakeTest, MoveUp)
{
	test_move(*this, UP, {_bodyPositions.front().first, _bodyPositions.front().second - 1});
}

TEST_F(SnakeTest, MoveRight)
{
	test_move(*this, RIGHT, {_bodyPositions.front().first + 1, _bodyPositions.front().second});
}

TEST_F(SnakeTest, MoveLeft)
{
	test_move(*this, LEFT, {_bodyPositions.front().first - 1, _bodyPositions.front().second});
}

TEST_F(SnakeTest, MoveDown)
{
	test_move(*this, DOWN, {_bodyPositions.front().first, _bodyPositions.front().second + 1});
}
