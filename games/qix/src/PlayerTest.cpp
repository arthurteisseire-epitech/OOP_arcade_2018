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
		ASSERT_EQ(_x, 0);
		ASSERT_EQ(_y, 0);
	}
}
