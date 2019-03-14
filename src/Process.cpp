/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Process.cpp
*/

#include <iostream>
#include "Process.hpp"

const std::unordered_map<arc::ComponentType, void (arc::IGraphic::*)(
	const arc::IComponent &)> arc::Process::_graph_func_map = {
	{SPRITE, (void (IGraphic::*)(const IComponent &)) &IGraphic::processSprite},
	{TEXT,   (void (IGraphic::*)(const IComponent &)) &IGraphic::processText}
};

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
			arc::Process::any(component, graphic, _graph_func_map.at(component.get().getType()));
		} catch (...) {
			std::cerr << "Unknown type: " << component.get().getType() << std::endl;
		}
	}
}

void arc::Process::any(std::reference_wrapper<IComponent> comp, IGraphic *graphic,
		       void (IGraphic::*func)(const IComponent &))
{
	(graphic->*func)((comp.get()));
}
