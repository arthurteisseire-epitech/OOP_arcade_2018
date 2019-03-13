/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Process.cpp
*/

#include "Process.hpp"

void arc::Process::sprites(const std::vector<std::reference_wrapper<ISprite>> sprites, IGraphic *graphic)
{
	for (auto sprite : sprites)
		graphic->processSprite(sprite);
}

void arc::Process::all(std::vector<std::reference_wrapper<IComponent>> components, IGraphic *graphic)
{
	std::vector<std::reference_wrapper<ISprite>> sprites_vec;

	for (auto sprite : components)
		if (sprite.get().getType() == SPRITE)
			sprites_vec.emplace_back(std::reference_wrapper<ISprite>(dynamic_cast<ISprite &>(sprite.get())));
	sprites(sprites_vec, graphic);
}