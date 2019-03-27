/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** PlayerName.cpp
*/

#include "Audio.hpp"
#include "PlayerName.hpp"

const int arc::PlayerName::FONT_SIZE = 20;

const std::string arc::PlayerName::PREFIX = "Player Name : ";

const std::map<arc::Key, void (arc::PlayerName::*)()> arc::PlayerName::_keysMap = {
	{LEFT,  &arc::PlayerName::moveFocusLeft},
	{RIGHT, &arc::PlayerName::moveFocusRight},
	{UP,    &arc::PlayerName::moveFocusUp},
	{DOWN,  &arc::PlayerName::moveFocusDown},
	{ENTER, &arc::PlayerName::action},
};

arc::PlayerName::PlayerName(const std::shared_ptr<SharedData> &playerData) :
	Scene(playerData),
	_playerText(std::make_unique<Text>(PREFIX + _playerData->playerName,
	                                   std::pair<float, float>(0.1, 0.1), FONT_SIZE)),
	_focus(0, 0)
{
	_gridLetters.emplace_back("ABCDEFGH", std::pair<float, float>(0.1, 0.2), FONT_SIZE);
	_gridLetters.emplace_back("IJKLMNOP", std::pair<float, float>(0.1, 0.3), FONT_SIZE);
	_gridLetters.emplace_back("QRSTUVWX", std::pair<float, float>(0.1, 0.4), FONT_SIZE);
	_gridLetters.emplace_back("YZ", std::pair<float, float>(0.1, 0.5), FONT_SIZE);
	_gridLetters.emplace_back("<~", std::pair<float, float>(0.1, 0.6), FONT_SIZE);
	_cursor = std::make_unique<Cursor>(getFocus());
}

void arc::PlayerName::update(const std::map<Key, KeyState> &keys, float)
{
	for (auto &key : keys) {
		auto it = _keysMap.find(key.first);
		if (it != _keysMap.end() && key.second == PRESSED)
			(this->*it->second)();
	}
}

void arc::PlayerName::moveFocusLeft()
{
	if (in(_focus.first - 1, _focus.second))
		--_focus.first;
	_cursor->changeFocus(getFocus());
}

void arc::PlayerName::moveFocusRight()
{
	if (in(_focus.first + 1, _focus.second))
		++_focus.first;
	_cursor->changeFocus(getFocus());
}

void arc::PlayerName::moveFocusUp()
{
	if (in(_focus.first, _focus.second - 1))
		--_focus.second;
	_cursor->changeFocus(getFocus());
}

void arc::PlayerName::moveFocusDown()
{
	if (in(_focus.first, _focus.second + 1))
		++_focus.second;
	_cursor->changeFocus(getFocus());
}

void arc::PlayerName::action()
{
	if (getFocus()->getText() == "<") {
		_playerData->playerName = _playerData->playerName.substr(0, _playerData->playerName.length() - 1);
		_playerText->setText(PREFIX + _playerData->playerName);
	} else if (_playerData->playerName.length() < 3 && getFocus()->getText() != "~")
		_playerText->setText(PREFIX + (_playerData->playerName += getFocus()->getText()));
}

arc::Text *arc::PlayerName::getFocus() const
{
	return _gridLetters[_focus.second].getLetter(_focus.first);
}

bool arc::PlayerName::in(int x, int y) const
{
	return (y >= 0 && y < (int)_gridLetters.size()) &&
	       (x >= 0 && x < (int)_gridLetters[y].size());
}

arc::SCENE arc::PlayerName::nextScene(const std::map<Key, KeyState> &keys) const
{
	auto enterKey = keys.find(ENTER);
	if (enterKey != keys.end() &&
	    enterKey->second == PRESSED &&
	    _playerData->playerName.length() == 3 &&
	    getFocus()->getText() == "~")
		return MENU;
	return PLAYER_NAME;
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::PlayerName::getComponents() const
{
	auto wrapper = std::vector<std::reference_wrapper<const IComponent>>();

	wrapper.reserve(1 + _gridLetters.size() * _gridLetters[0].size());
	wrapper.emplace_back(*_cursor);
	for (auto &row : _gridLetters)
		for (int i = 0; i < (int)row.size(); ++i)
			wrapper.emplace_back(*row.getLetter(i));
	wrapper.emplace_back(*_playerText);
	return wrapper;
}
