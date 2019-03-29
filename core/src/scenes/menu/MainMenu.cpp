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
	_spriteFocus("assets/sprites/focus.png"),
	_logo("assets/sprites/logo.png", {0.8, 0.2}, {0.1, 0.1}),
	_focus(0)
{
	_buttons.emplace_back("assets/sprites/sample.jpg", PLAYER_NAME, "Player Name");
	_buttons.emplace_back("assets/sprites/saple.jpg", GAME, "Play");
	_buttons.emplace_back("assets/sprites/sample.jpg", EXIT, "ScoreBoard");
	_buttons.emplace_back("assets/sprites/sample.jpg", EXIT, "Exit");
	setSpritesSize();
	setSpritesPosition();
}

void arc::MainMenu::setTextsString()
{
	_texts.clear();
	_texts.emplace_back("Games : ", std::make_pair<float, float>(0.06, 0.85), 20);
	for (size_t i = 0; i < _playerData->games.size(); ++i) {
		std::string isCurrent = _playerData->games[i] == _playerData->gameName ? " <-" : "";
		_texts.emplace_back(_playerData->games[i] + isCurrent,
		                    std::make_pair<float, float>(0.17, (i / 50.0f) + 0.85), 20);
	}
	_texts.emplace_back("Graphics : ", std::make_pair<float, float>(0.76, 0.85), 20);
	for (size_t i = 0; i < _playerData->libs.size(); ++i) {
		std::string isCurrent = _playerData->libs[i] == _playerData->libname ? " <-" : "";
		_texts.emplace_back(_playerData->libs[i] + isCurrent,
		                    std::make_pair<float, float>(0.87, (i / 50.0f) + 0.85), 20);
	}
}

void arc::MainMenu::setSpritesPosition()
{
	_spriteFocus.setPosition(std::pair<float, float>(0.05, 0.4));
	_buttons[0].setPosition(std::pair<float, float>(0.2, 0.4));
	_buttons[1].setPosition(std::pair<float, float>(0.2, 0.5));
	_buttons[2].setPosition(std::pair<float, float>(0.2, 0.6));
	_buttons[3].setPosition(std::pair<float, float>(0.2, 0.7));
}

void arc::MainMenu::setSpritesSize()
{
	float width = 0.6;
	float height = 0.05;

	_spriteFocus.setSize(std::pair<float, float>(0.15, height));
	_buttons[0].setSize(std::pair<float, float>(width, height));
	_buttons[1].setSize(std::pair<float, float>(width, height));
	_buttons[2].setSize(std::pair<float, float>(width, height));
	_buttons[3].setSize(std::pair<float, float>(width, height));
}

void arc::MainMenu::update(const std::map<Key, KeyState> &keys, float)
{
	_playerName.setText("Player Name : " + _playerData->playerName);
	setTextsString();
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

	wrapper.reserve(_buttons.size() * 2 + 2 + _texts.size());
	for (const auto &button : _buttons)
		wrapper.emplace_back(button.getSprite());
	wrapper.emplace_back(_spriteFocus);
	wrapper.emplace_back(_logo);

	for (const auto &button : _buttons)
		wrapper.emplace_back(button.getText());
	wrapper.emplace_back(_playerName);

	for (const auto &text : _texts)
		wrapper.emplace_back(text);
	return wrapper;
}
