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
	static const std::pair<unsigned int, unsigned int> init_pos;
	static const std::pair<unsigned int, unsigned int> move;

	void test_move(Snake &snake, Direction direction, pos_t expected_head);
};

const std::pair<unsigned int, unsigned int> SnakeTest::init_pos = {1, 2};

TEST_F(SnakeTest, Init)
{
	EXPECT_EQ(_body_positions.size(), (size_t)4);
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

void SnakeTest::test_move(Snake &snake, Direction direction, pos_t expected_head)
{
	body_t pos_list = _body_positions;

	snake.move_body(direction);
	EXPECT_EQ(_body_positions.front(), expected_head);
	pos_list.pop_back();
	for (size_t i = 0; i < pos_list.size(); ++i)
		EXPECT_EQ(pos_list[i], _body_positions[i + 1]);
}

TEST_F(SnakeTest, MoveUp)
{
	test_move(*this, UP, {_body_positions.front().first, _body_positions.front().second - 1});
}

TEST_F(SnakeTest, MoveRight)
{
	test_move(*this, RIGHT, {_body_positions.front().first + 1, _body_positions.front().second});
}

TEST_F(SnakeTest, MoveLeft)
{
	test_move(*this, LEFT, {_body_positions.front().first - 1, _body_positions.front().second});
}

TEST_F(SnakeTest, MoveDown)
{
	test_move(*this, DOWN, {_body_positions.front().first, _body_positions.front().second + 1});
}
