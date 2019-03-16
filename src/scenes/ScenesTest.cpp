/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ScenesTest.cpp
*/

#include "gtest/gtest.h"
#include "Scenes.hpp"

class ScenesTest : public ::testing::Test, public arc::Scenes {
};

TEST_F(ScenesTest, changeScene)
{
	EXPECT_EQ(_currScene, 0);
	changeScene(1);
	EXPECT_EQ(_currScene, 1);
}
