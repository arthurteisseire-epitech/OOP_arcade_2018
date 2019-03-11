/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Process.hpp
*/

#ifndef ARCADE_PROCESS_HPP
#define ARCADE_PROCESS_HPP

#include <vector>
#include <memory>
#include "IGraphic.hpp"

class Process {
public:
	static void sprites(const std::vector<std::unique_ptr<ISprite>> &sprites, IGraphic *graphic);
};

#endif
