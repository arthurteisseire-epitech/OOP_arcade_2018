/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Nibbler.cpp,
*/

#include <memory>
#include "Nibbler.hpp"
#include "Sprite.hpp"
#include "Text.hpp"

arc::IGame *entryPoint(int &ac, char *av[])
{
	return new arc::Nibbler(ac, av);
}

arc::Nibbler::Nibbler(int &, char **) :
	_score(0),
	_size(50),
	_map(_size)
{
}

std::vector<std::reference_wrapper<arc::IComponent>> arc::Nibbler::getComponents() const
{
	std::vector<std::reference_wrapper<IComponent>> vec;
	IComponent *score = new Text(std::string("Score: ") + std::to_string(_score), std::pair<float, float>(0.1, 0.1));

	_map.generateSprites(vec);
	vec.emplace_back(*score);
	return vec;
}

void arc::Nibbler::update(std::map<arc::Key, arc::KeyState> keys, float deltaTime)
{

}
