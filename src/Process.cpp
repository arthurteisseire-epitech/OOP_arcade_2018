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


void arc::Process::all(std::vector<std::reference_wrapper<IComponent>> components, IGraphic *graphic)
{
	for (auto component : components) {
		try {
			arc::Process::any(component, graphic);
		} catch (...) {
			std::cerr << "Unknown type: " << component.get().getType() << std::endl;
		}
	}
}

void arc::Process::any(std::reference_wrapper<IComponent> comp, IGraphic *graphic)
{
	if (comp.get().getType() == SPRITE)
		graphic->processSprite(dynamic_cast<ISprite &>(comp.get()));
	else if (comp.get().getType() == TEXT)
		graphic->processText(dynamic_cast<IText &>(comp.get()));
}