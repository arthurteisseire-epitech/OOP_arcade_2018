/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** PlayerName.cpp
*/

#include "Audio.hpp"
#include "PlayerName.hpp"

std::map<arc::Key, void (arc::PlayerName::*)()> arc::PlayerName::_keysMap = {
	{LEFT,  &arc::PlayerName::moveFocusLeft},
	{RIGHT, &arc::PlayerName::moveFocusRight},
};

arc::PlayerName::PlayerName() :
	_playerName(std::make_unique<Text>("", std::pair<float, float>(0.1, 0.1), 20)),
	_focus(0, 0)
{
	std::string letter = "A";

	_gridLetters.emplace_back("ABCDEFGH", std::pair<float, float>(0.2, 0.2), 20);
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

	for (size_t i = 0; i < _gridLetters[0].size(); ++i)
		wrapper.emplace_back(*_gridLetters[0].getLetter(i));
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
	auto last = _gridLetters[_focus.second].size() == 0 ? 0 : _gridLetters[_focus.second].size() - 1;

	if (_focus.first != 0)
		--_focus.first;
	else
		_focus.first = last;
	_cursor->changeFocus(getFocus());
}

void arc::PlayerName::moveFocusRight()
{
	if (_focus.first < _gridLetters[0].size() - 1)
		++_focus.first;
	else
		_focus.first = 0;
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
