/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** PlayerName.cpp
*/

#include "Audio.hpp"
#include "PlayerName.hpp"

arc::PlayerName::PlayerName()
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

void arc::PlayerName::processEvents(const std::map<arc::Key, arc::KeyState> &)
{
}
