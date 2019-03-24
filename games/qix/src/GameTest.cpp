/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** GameTest.cpp
*/

#include "gtest/gtest.h"
#include "Game.hpp"

namespace arc {
	class GameTest : public Game, public ::testing::Test {
	};

	TEST_F(GameTest, movePlayer)
	{
		movePlayerUp();
//		ASSERT_TRUE(_map.isIn(_player));
//		ASSERT_TRUE(_player.isIn(_map));
	}
}

