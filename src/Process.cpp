/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Process.cpp
*/

#include <iostream>
#include "Process.hpp"

const std::unordered_map<ComponentType, void (IGraphic::*)(const IComponent &)> Process::_graph_func_map = {
	{SPRITE, (void (IGraphic::*)(const IComponent &)) &IGraphic::processSprite},
	{TEXT, (void (IGraphic::*)(const IComponent &)) &IGraphic::processText}
};

void Process::sprites(const std::vector<std::reference_wrapper<ISprite>> sprites, IGraphic *graphic)
{
	for (auto sprite : sprites)
		graphic->processSprite(sprite.get());
}

void Process::texts(const std::vector<std::reference_wrapper<IText>> texts, IGraphic *graphic)
{
	for (auto text : texts)
		graphic->processText(text.get());
}

/*
void Process::all(std::vector<std::reference_wrapper<IComponent>> components, IGraphic *graphic)
{
	std::vector<std::reference_wrapper<ISprite>> sprites_vec;
	std::vector<std::reference_wrapper<IText>> text_vec;

	for (auto comp : components)
		sprites_vec.emplace_back(comp);
	sprites(sprites_vec, graphic);
	texts(text_vec, graphic);
}
*/

void Process::all(std::vector<std::reference_wrapper<IComponent>> components, IGraphic *graphic)
{
	for (auto component : components) {
		try {
			Process::any(component, graphic, _graph_func_map.at(component.get().getType()));
		} catch (...) {
			std::cerr << "Unknown type: " << component.get().getType() << std::endl;
		}
	}
}

void Process::any(std::reference_wrapper<IComponent> comp, IGraphic *graphic, void (IGraphic::*func)(const IComponent &))
{
	(graphic->*func)((comp.get()));
}