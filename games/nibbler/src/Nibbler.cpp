/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Nibbler.cpp
*/

#include <memory>
#include "Nibbler.hpp"
#include "Sprite.hpp"
#include "Text.hpp"

#include <iostream>
arc::IGame *gameEntryPoint(int &ac, char **av)
{
	return new arc::Nibbler(ac, av);
}

arc::Nibbler::Nibbler(int &, char **av) :
	_score(0),
	_size(50),
	_map({_size, _size})
{
	srand((unsigned int)(unsigned long)(av));
}

std::vector<std::reference_wrapper<arc::IComponent>> arc::Nibbler::getComponents() const
{
	std::vector<std::reference_wrapper<IComponent>> vec;
	IComponent *score = new Text(std::string("Score: ") + std::to_string(_score), std::pair<float, float>(0.4, 0.2), 20);

	_map.generateSprites(vec);
	vec.emplace_back(*score);
	return vec;
}

void arc::Nibbler::update(const std::map<arc::Key, arc::KeyState> &keys, float deltaTime)
{

}

bool arc::Nibbler::isRunning() const
{
	return false;
}
