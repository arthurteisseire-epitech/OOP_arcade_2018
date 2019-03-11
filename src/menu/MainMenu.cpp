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
	_sprites.push_back(std::unique_ptr<Sprite>(new Sprite("assets/sample.jpg")));
	_sprites.push_back(std::unique_ptr<Sprite>(new Sprite("assets/sample.jpg")));
	setSpritesPosition();
	setSpritesSize();
}

const std::vector<std::unique_ptr<ISprite>> &MainMenu::getSprites()
{
        return _sprites;
}

void MainMenu::setSpritesPosition()
{
	dynamic_cast<Sprite *>(_sprites[0].get())->setPosition(std::pair<float, float>(200, 300));
	dynamic_cast<Sprite *>(_sprites[1].get())->setPosition(std::pair<float, float>(200, 500));
	dynamic_cast<Sprite *>(_sprites[2].get())->setPosition(std::pair<float, float>(200, 700));
}

void MainMenu::setSpritesSize()
{
	float height = 100;
	float width = 200;

	dynamic_cast<Sprite *>(_sprites[0].get())->setSize(std::pair<float, float>(height, width));
	dynamic_cast<Sprite *>(_sprites[1].get())->setSize(std::pair<float, float>(height, width));
	dynamic_cast<Sprite *>(_sprites[2].get())->setSize(std::pair<float, float>(height, width));
}
