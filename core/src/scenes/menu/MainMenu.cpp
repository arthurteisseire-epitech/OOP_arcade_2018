/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MainMenu.cpp
*/

#include <memory>
#include <algorithm>
#include <map>
#include <functional>
#include "Key.hpp"
#include "MainMenu.hpp"

std::map<arc::Key, void (arc::MainMenu::*)()> arc::MainMenu::_keysMap = {
	{UP,   &arc::MainMenu::moveFocusUp},
	{DOWN, &arc::MainMenu::moveFocusDown},
};

arc::MainMenu::MainMenu(const std::shared_ptr<SharedData> &playerData) :
	Scene(playerData),
	_playerName("Player Name : " + _playerData->playerName, std::pair<float, float>(0.1, 0.1), 20),
	_spriteFocus("assets/focus.png"),
	_focus(0)
{
	_audios.emplace_back("assets/audio/sound.m4a", 10);
	_buttons.emplace_back("assets/sample.jpg", PLAYER_NAME, "Player Name");
	_buttons.emplace_back("assets/saple.jpg", GAME, "Play");
	_buttons.emplace_back("assets/sample.jpg", EXIT, "Exit");
	setSpritesSize();
	setSpritesPosition();
}

void arc::MainMenu::setSpritesPosition()
{
	_spriteFocus.setPosition(std::pair<float, float>(0.05, 0.2));
	_buttons[0].setPosition(std::pair<float, float>(0.2, 0.2));
	_buttons[1].setPosition(std::pair<float, float>(0.2, 0.4));
	_buttons[2].setPosition(std::pair<float, float>(0.2, 0.6));
}

void arc::MainMenu::setSpritesSize()
{
	float width = 0.6;
	float height = 0.1;

	_spriteFocus.setSize(std::pair<float, float>(0.15, height));
	_buttons[0].setSize(std::pair<float, float>(width, height));
	_buttons[1].setSize(std::pair<float, float>(width, height));
	_buttons[2].setSize(std::pair<float, float>(width, height));
}

void arc::MainMenu::update(const std::map<Key, KeyState> &keys, float)
{
	_playerName.setText("Player Name : " + _playerData->playerName);
	for (auto &p : _keysMap) {
		auto it = keys.find(p.first);
		if (it != keys.end() && it->second == PRESSED)
			(this->*p.second)();
	}
}

void arc::MainMenu::moveFocusDown()
{
	if (_focus != _buttons.size() - 1) {
		++_focus;
		_spriteFocus.moveDown(_buttons[_focus].getSprite().getPosition().second -
		                       _spriteFocus.getPosition().second);
	}
}

void arc::MainMenu::moveFocusUp()
{
	if (_focus != 0) {
		--_focus;
		_spriteFocus.moveUp(_spriteFocus.getPosition().second - _buttons[_focus].getPosition().second);
	}
}

arc::SCENE arc::MainMenu::nextScene(const std::map<Key, KeyState> &keys) const
{
	auto enterKey = keys.find(ENTER);
	if (enterKey != keys.end() && enterKey->second == PRESSED)
		return _buttons[_focus].getLinkedScene();
	return MENU;
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::MainMenu::getComponents() const
{
	std::vector<std::reference_wrapper<const arc::IComponent>> wrapper;

	wrapper.reserve(_buttons.size() * 2 + 1 + _audios.size());
	for (const auto &button : _buttons)
		wrapper.emplace_back(button.getSprite());
	wrapper.emplace_back(_spriteFocus);

	for (const auto &button : _buttons)
		wrapper.emplace_back(button.getText());
	wrapper.emplace_back(_playerName);

	for (const auto &audio : _audios)
		wrapper.emplace_back(audio);
	return wrapper;
}
