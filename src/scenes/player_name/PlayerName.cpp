/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** PlayerName.cpp
*/

#include "Audio.hpp"
#include "PlayerName.hpp"

arc::PlayerName::PlayerName() = default;

std::vector<std::reference_wrapper<arc::ISprite>> arc::PlayerName::getSprites() const
{
	return std::vector<std::reference_wrapper<ISprite>>();
}

std::vector<std::reference_wrapper<arc::IText>> arc::PlayerName::getTexts() const
{
	return std::vector<std::reference_wrapper<IText>>();
}

std::vector<std::reference_wrapper<arc::IAudio>> arc::PlayerName::getAudios() const
{
	return std::vector<std::reference_wrapper<IAudio>>();
}

void arc::PlayerName::processEvents(const std::map<arc::Key, arc::KeyState> &)
{
}
