/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Process.cpp
*/

#include <iostream>
#include "Process.hpp"

void arc::Process::sprites(const std::vector<std::reference_wrapper<ISprite>> sprites, IGraphic *graphic)
{
	for (auto sprite : sprites)
		if (!graphic->processSprite(sprite.get()))
			std::cerr << "Process sprite failed for sprite: " << sprite.get().getTextureName() << std::endl;
}

void arc::Process::texts(const std::vector<std::reference_wrapper<IText>> texts, IGraphic *graphic)
{
	for (auto text : texts)
		if (!graphic->processText(text.get()))
			std::cerr << "Process text failed for text: " << text.get().getText() << std::endl;
}
