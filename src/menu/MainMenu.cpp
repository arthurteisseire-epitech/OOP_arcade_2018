/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MainMenu.cpp
*/

#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	_sprites.push_back(std::unique_ptr<Sprite>(new Sprite("assets/sample.jpg")));
}

const std::vector<std::unique_ptr<ISprite>> &MainMenu::getSprites()
{
        return _sprites;
}
