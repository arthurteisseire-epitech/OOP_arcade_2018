/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ScenesTest.cpp
*/

#include "gtest/gtest.h"
#include "Scenes.hpp"
#include "MainMenu.hpp"

namespace arc {
	class ScenesTest : public ::testing::Test, public Scenes {
	};

	TEST_F(ScenesTest, checkExistentScene)
	{
		EXPECT_NE(_scene, nullptr);
	}
}
