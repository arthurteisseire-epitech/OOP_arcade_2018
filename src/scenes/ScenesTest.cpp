/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ScenesTest.cpp
*/

#include <memory>
#include "gtest/gtest.h"
#include "SceneManager.hpp"
#include "MainMenu.hpp"

namespace arc {
	class ScenesTest : public ::testing::Test, public SceneManager {
	protected:
		ScenesTest() : SceneManager(new MainMenu) {};
		~ScenesTest() override = default;
	};

	TEST_F(ScenesTest, checkExistentScene)
	{
		EXPECT_NE(_scene, nullptr);
	}
}
