/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MainMenu.cpp
*/

#include <algorithm>
#include "MainMenu.hpp"

arc::MainMenu::MainMenu() :
	_focus(1)
{
	_sprites.push_back(std::unique_ptr<Sprite>(new Sprite("assets/focus.png")));
	_sprites.push_back(std::unique_ptr<Sprite>(new Sprite("assets/sample.jpg")));
	_sprites.push_back(std::unique_ptr<Sprite>(new Sprite("assets/sample.jpg")));
	_sprites.push_back(std::unique_ptr<Sprite>(new Sprite("assets/sample.jpg")));
	setSpritesPosition();
	setSpritesSize();
}

std::vector<std::reference_wrapper<ISprite>> arc::MainMenu::getSprites()
{
	std::vector<std::reference_wrapper<ISprite>> wrapper;

	for (const auto &sprite : _sprites)
		wrapper.push_back(*sprite);
        return wrapper;
}

void arc::MainMenu::setSpritesPosition()
{
	_sprites[0].get()->setPosition(std::pair<float, float>(0.2, 0.2));
	_sprites[1].get()->setPosition(std::pair<float, float>(0.2, 0.4));
	_sprites[2].get()->setPosition(std::pair<float, float>(0.2, 0.6));
	_sprites[3].get()->setPosition(std::pair<float, float>(0.2, 0.8));
}

void arc::MainMenu::setSpritesSize()
{
	float width = 0.6;
	float height = 0.1;

	_sprites[0].get()->setSize(std::pair<float, float>(width, height));
	_sprites[1].get()->setSize(std::pair<float, float>(width, height));
	_sprites[2].get()->setSize(std::pair<float, float>(width, height));
	_sprites[3].get()->setSize(std::pair<float, float>(width, height));
}

void arc::MainMenu::moveFocusDown()
{
	if (_focus != 1)
		--_focus;
}

void arc::MainMenu::moveFocusUp()
{
	if (_focus != _sprites.size() - 1)
		++_focus;
}
