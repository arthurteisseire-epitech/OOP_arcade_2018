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
	IComponent *sprite = new Sprite("assets/sample.jpg");
	IComponent *score = new Text(std::string("Score: ") + std::to_string(_score), std::pair<float, float>(0.5, 0.5));
	std::reference_wrapper<IComponent> sprite_ref_wrapper(*sprite);

	dynamic_cast<Sprite *>(sprite)->setSize(std::pair<float, float>(0.2, 0.2));
	vec.emplace_back(std::reference_wrapper<IComponent>(std::reference_wrapper<IComponent>(*sprite)));
//	vec.emplace_back(std::reference_wrapper<IComponent>(std::reference_wrapper<IComponent>(*score)));
	return vec;
}