/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** PlayerName.cpp
*/

#include "Audio.hpp"
#include "PlayerName.hpp"

int arc::PlayerName::FONT_SIZE = 20;

std::map<arc::Key, void (arc::PlayerName::*)()> arc::PlayerName::_keysMap = {
	{LEFT,  &arc::PlayerName::moveFocusLeft},
	{RIGHT, &arc::PlayerName::moveFocusRight},
	{UP,    &arc::PlayerName::moveFocusUp},
	{DOWN,  &arc::PlayerName::moveFocusDown},
};

arc::PlayerName::PlayerName() :
	_playerName(std::make_unique<Text>("", std::pair<float, float>(0.1, 0.1), FONT_SIZE)),
	_focus(0, 0)
{
	_gridLetters.emplace_back("ABCDEFGH", std::pair<float, float>(0.1, 0.2), FONT_SIZE);
	_gridLetters.emplace_back("IJKLMNOP", std::pair<float, float>(0.1, 0.3), FONT_SIZE);
	_gridLetters.emplace_back("QRSTUVWX", std::pair<float, float>(0.1, 0.4), FONT_SIZE);
	_gridLetters.emplace_back("YZ_", std::pair<float, float>(0.1, 0.5), FONT_SIZE);
	_cursor = std::make_unique<Cursor>(getFocus());
}

std::vector<std::reference_wrapper<arc::ISprite>> arc::PlayerName::getSprites() const
{
	auto wrapper = std::vector<std::reference_wrapper<ISprite>>();

	wrapper.emplace_back(*_cursor);
	return wrapper;
}

std::vector<std::reference_wrapper<arc::IText>> arc::PlayerName::getTexts() const
{
	auto wrapper = std::vector<std::reference_wrapper<IText>>();

	for (auto &row : _gridLetters) {
		for (int i = 0; i < (int)row.size(); ++i)
			wrapper.emplace_back(*row.getLetter(i));
	}
	wrapper.emplace_back(*_playerName);
	return wrapper;
}

std::vector<std::reference_wrapper<arc::IAudio>> arc::PlayerName::getAudios() const
{
	return std::vector<std::reference_wrapper<IAudio>>();
}

void arc::PlayerName::processEvents(const std::map<arc::Key, arc::KeyState> &keys)
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

void arc::PlayerName::action(arc::SceneManager &)
{
	_playerName->setText(_playerName->getText() + getFocus()->getText());
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

