/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MainMenu.cpp
*/

#include "MainMenu.hpp"

arc::MainMenu::MainMenu()
{
	_sprites.push_back(std::unique_ptr<Sprite>(new Sprite("assets/focus.jpeg")));
	_sprites.push_back(std::unique_ptr<Sprite>(new Sprite("assets/sample.jpg")));
	_sprites.push_back(std::unique_ptr<Sprite>(new Sprite("assets/sample.jpg")));
	setSpritesPosition();
	setSpritesSize();
}

const std::vector<std::unique_ptr<ISprite>> &arc::MainMenu::getSprites()
{
        return _sprites;
}

void arc::MainMenu::setSpritesPosition()
{
	dynamic_cast<Sprite *>(_sprites[0].get())->setPosition(std::pair<float, float>(0.2, 0.2));
	dynamic_cast<Sprite *>(_sprites[1].get())->setPosition(std::pair<float, float>(0.2, 0.4));
	dynamic_cast<Sprite *>(_sprites[2].get())->setPosition(std::pair<float, float>(0.2, 0.6));
}

void arc::MainMenu::setSpritesSize()
{
	float width = 0.6;
	float height = 0.1;

	dynamic_cast<Sprite *>(_sprites[0].get())->setSize(std::pair<float, float>(width, height));
	dynamic_cast<Sprite *>(_sprites[1].get())->setSize(std::pair<float, float>(width, height));
	dynamic_cast<Sprite *>(_sprites[2].get())->setSize(std::pair<float, float>(width, height));
}
