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

IGame *entryPoint(int &ac, char *av[])
{
	return new Nibbler(ac, av);
}

Nibbler::Nibbler(int &, char **) : _score(0)
{
}

std::vector<std::reference_wrapper<IComponent>> Nibbler::getComponents()
{
	std::vector<std::reference_wrapper<IComponent>> vec;
	IComponent *sprite = new Sprite("games/nibbler/assets/snake_head_up.png");
	IComponent *score = new Text(std::string("Score: ") + std::to_string(_score), std::pair<float, float>(0.1, 0.1));
	std::reference_wrapper<IComponent> sprite_ref_wrapper(*sprite);

	dynamic_cast<Sprite *>(sprite)->setSize(std::pair<float, float>(0.1, 0.1));
	vec.emplace_back(*sprite);
	vec.emplace_back(*score);
	return vec;
}