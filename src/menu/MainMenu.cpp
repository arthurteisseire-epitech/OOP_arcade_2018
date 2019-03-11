/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MainMenu.cpp
*/

#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	_sprites.emplace_back("assets/sample.jpg");
}

const Sprite &MainMenu::getSprite(size_t idx)
{
	return _sprites[idx];
}
