/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Converter.cpp
*/

#include "Converter.hpp"

std::pair<float, float> arc::Converter::PosToPourcent(arc::Position pos, int width, int height)
{
	return {(float)pos.x / (float)width,
	        (float)pos.y / (float)height};
}

std::pair<float, float> arc::Converter::SizeToPourcent(int width, int height)
{
	return {1.0f / width, 1.0f / height};
}
