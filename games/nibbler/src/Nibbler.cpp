/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Nibbler.cpp,
*/

#include <memory>
#include "Nibbler.hpp"
#include "Sprite.hpp"

IGame *entryPoint(int &ac, char *av[])
{
	return new Nibbler(ac, av);
}

std::vector<std::reference_wrapper<IComponent>> Nibbler::getComponents()
{
	std::vector<std::reference_wrapper<IComponent>> vec;
	IComponent *sprite = new Sprite("assets/sample.png");
	std::reference_wrapper<IComponent> sprite_ref_wrapper(*sprite);

	dynamic_cast<Sprite *>(sprite)->setSize(std::pair<float, float>(0.5, 0.5));
	vec.emplace_back(std::reference_wrapper<IComponent>(sprite_ref_wrapper));
	return vec;
}

Nibbler::Nibbler(int &, char **)
{
}