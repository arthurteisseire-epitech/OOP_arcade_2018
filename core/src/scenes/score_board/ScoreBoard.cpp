/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ScoreBoard.cpp
*/

#include "ScoreBoard.hpp"

arc::ScoreBoard::ScoreBoard(const std::shared_ptr<arc::SharedData> &playerData) :
	Scene(playerData)
{
}

void arc::ScoreBoard::update(const std::map<arc::Key, arc::KeyState> &, float)
{
}

std::vector<std::reference_wrapper<const arc::IComponent>> arc::ScoreBoard::getComponents() const
{
	return std::vector<std::reference_wrapper<const arc::IComponent>>();
}

arc::SCENE arc::ScoreBoard::nextScene(const std::map<arc::Key, arc::KeyState> &keys) const
{
	return SCOREBOARD;
}
