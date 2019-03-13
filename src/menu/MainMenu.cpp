/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MainMenu.cpp
*/

#include <algorithm>
#include <map>
#include <functional>
#include "Key.hpp"
#include "MainMenu.hpp"

std::map<Key, void (arc::MainMenu::*)()> arc::MainMenu::KeysFunctions = {
	{UP, &arc::MainMenu::moveFocusUp},
	{DOWN, &arc::MainMenu::moveFocusDown},
};

arc::MainMenu::MainMenu() :
	_focus(0)
{
	_spriteFocus = std::unique_ptr<Sprite>(new Sprite("assets/focus.png"));
	_buttons.push_back(std::unique_ptr<Sprite>(new Sprite("assets/sample.jpg")));
	_buttons.push_back(std::unique_ptr<Sprite>(new Sprite("assets/sample.jpg")));
	_buttons.push_back(std::unique_ptr<Sprite>(new Sprite("assets/sample.jpg")));
	setSpritesPosition();
	setSpritesSize();
}

std::vector<std::reference_wrapper<ISprite>> arc::MainMenu::getSprites()
{
	std::vector<std::reference_wrapper<ISprite>> wrapper;

	for (const auto &button : _buttons)
		wrapper.push_back(*button);
	wrapper.push_back(*_spriteFocus);
        return wrapper;
}

void arc::MainMenu::setSpritesPosition()
{
	_spriteFocus->setPosition(std::pair<float, float>(0.05, 0.2));
	_buttons[0]->setPosition(std::pair<float, float>(0.2, 0.2));
	_buttons[1]->setPosition(std::pair<float, float>(0.2, 0.4));
	_buttons[2]->setPosition(std::pair<float, float>(0.2, 0.6));
}

void arc::MainMenu::setSpritesSize()
{
	float width = 0.6;
	float height = 0.1;

	_spriteFocus->setSize(std::pair<float, float>(0.15, height));
	_buttons[0]->setSize(std::pair<float, float>(width, height));
	_buttons[1]->setSize(std::pair<float, float>(width, height));
	_buttons[2]->setSize(std::pair<float, float>(width, height));
}

void arc::MainMenu::processEvents(const std::vector<Key> &vector)
{
	for (auto &keyFunc : KeysFunctions)
		if (std::find(vector.begin(), vector.end(), keyFunc.first) != vector.end())
			(this->*keyFunc.second)();
}

void arc::MainMenu::moveFocusDown()
{
	if (_focus != _buttons.size() - 1) {
		++_focus;
		_spriteFocus->moveDown(_buttons[_focus]->getPosition().second - _spriteFocus->getPosition().second);
	}
}

void arc::MainMenu::moveFocusUp()
{
	if (_focus != 0) {
		--_focus;
		_spriteFocus->moveUp(_spriteFocus->getPosition().second - _buttons[_focus]->getPosition().second);
	}
}
