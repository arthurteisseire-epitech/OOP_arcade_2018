/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** PlayerTest.cpp
*/

#include "gtest/gtest.h"
#include "Player.hpp"

namespace arc {
	class PlayerTest : public Player, public ::testing::Test {
	};

	TEST_F(PlayerTest, position)
	{
		ASSERT_EQ(_pos, Position(0, 0));
	}

	TEST_F(PlayerTest, verticalMove)
	{
		move(UP);
		ASSERT_EQ(_pos, Position(0, -1));
		move(DOWN);
		ASSERT_EQ(_pos, Position(0, 0));
		move(DOWN);
		ASSERT_EQ(_pos, Position(0, 1));
	}

	TEST_F(PlayerTest, horizontalMove)
	{
		move(LEFT);
		ASSERT_EQ(_pos, Position(-1, 0));
		move(RIGHT);
		ASSERT_EQ(_pos, Position(0, 0));
		move(RIGHT);
		ASSERT_EQ(_pos, Position(1, 0));
	}
}
