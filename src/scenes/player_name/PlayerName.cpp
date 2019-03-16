/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** PlayerName.cpp
*/

#include "Audio.hpp"
#include "PlayerName.hpp"

std::map<arc::Key, void (arc::PlayerName::*)()> arc::PlayerName::_keysMap = {
	{LEFT, &arc::PlayerName::moveFocusLeft},
	{RIGHT, &arc::PlayerName::moveFocusRight},
};

arc::PlayerName::PlayerName() :
	_focus(0)
{
	std::string letter = "A";

	for (size_t i = 0; i < 8; ++i) {
		_letters.push_back(std::make_unique<Text>(letter, std::pair<float, float>(i / 10.0, 0.1), 20));
		letter[0]++;
	}
        _cursor = std::make_unique<Cursor>(_letters[0].get());
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

	for (auto &letter : _letters)
		wrapper.emplace_back(*letter);
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
		if (it != _keysMap.end() && key.second == RELEASED)
			(this->*it->second)();
	}
}

void arc::PlayerName::moveFocusLeft()
{
	auto last = _letters.empty() ? 0 : _letters.size() - 1;

	if (_focus != 0)
		--_focus;
	else
		_focus = last;
	_cursor->changeFocus(_letters[_focus].get());
}

void arc::PlayerName::moveFocusRight()
{
	if (_focus < _letters.size() - 1)
		++_focus;
	else
		_focus = 0;
	_cursor->changeFocus(_letters[_focus].get());
}
