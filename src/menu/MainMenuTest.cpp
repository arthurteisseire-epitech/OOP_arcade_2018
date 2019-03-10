/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MainMenuTest.cpp
*/

#include "gtest/gtest.h"
#include "MainMenu.hpp"

TEST(MainMenu, load)
{
	MainMenu menu;

	menu.loadSprites();
}
