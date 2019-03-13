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

namespace arc {
	class Process {
	public:
		static void all(std::vector<std::reference_wrapper<IComponent>> components, IGraphic *graphic);
		static void sprites(const std::vector<std::reference_wrapper<ISprite>> &sprites, IGraphic *graphic);
		static void sprites(const std::vector<std::unique_ptr<ISprite>> &sprites, IGraphic *graphic);
	};
}

#endif
