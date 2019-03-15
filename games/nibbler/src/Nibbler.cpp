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

arc::Nibbler::Nibbler(int &, char **) : _score(0)
{
}

std::vector<std::reference_wrapper<arc::IComponent>> arc::Nibbler::getComponents() const
{
	std::vector<std::reference_wrapper<IComponent>> vec;
	IComponent *sprite = new Sprite("games/nibbler/assets/sprites/snake_head_up.png");
	IComponent *score = new Text(std::string("Score: ") + std::to_string(_score), std::pair<float, float>(0.1, 0.1));
	std::reference_wrapper<IComponent> sprite_ref_wrapper(*sprite);

	dynamic_cast<Sprite *>(sprite)->setSize(std::pair<float, float>(0.1, 0.1));
	dynamic_cast<Sprite *>(sprite)->setPosition(std::pair<float, float>(0.1, 0.1));
	vec.emplace_back(*sprite);
	vec.emplace_back(*score);
	return vec;
}

void arc::Nibbler::update(std::map<arc::Key, arc::KeyState> keys, float deltaTime)
{

}
