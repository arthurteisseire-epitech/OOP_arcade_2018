/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Process.cpp
*/

#include <iostream>
#include "Process.hpp"

void arc::Process::sprites(const std::vector<std::reference_wrapper<ISprite>> &sprites, IGraphic *graphic)
{
	for (auto sprite : sprites)
		graphic->processSprite(sprite.get());
}

void arc::Process::texts(const std::vector<std::reference_wrapper<IText>> &texts, IGraphic *graphic)
{
	for (auto text : texts)
		graphic->processText(text.get());
}

void arc::Process::audios(const std::vector<std::reference_wrapper<IAudio>> &audios, arc::IGraphic *graphic)
{
	for (auto audio : audios)
		graphic->processAudio(audio.get());
}
