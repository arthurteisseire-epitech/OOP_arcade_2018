/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ScenesTest.cpp
*/

#include "gtest/gtest.h"
#include "Scenes.hpp"

namespace arc {
	class ScenesTest : public ::testing::Test, public Scenes {
	};

	TEST_F(ScenesTest, changeScene)
	{
		EXPECT_EQ(_currScene, MENU);
		changeScene(PLAYER_NAME);
		EXPECT_EQ(_currScene, PLAYER_NAME);
	}
}
