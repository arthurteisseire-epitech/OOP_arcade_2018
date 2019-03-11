/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Process.cpp
*/

#include "Process.hpp"

void Process::sprites(const std::vector<std::unique_ptr<ISprite>> &sprites, IGraphic *graphic)
{
	for (auto &sprite : sprites)
		graphic->processSprite(*sprite);
}
