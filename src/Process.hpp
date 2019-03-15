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
#include <unordered_map>
#include "IGraphic.hpp"

namespace arc {
	class Process {
	public:
		static void all(std::vector<std::reference_wrapper<IComponent>> components, IGraphic *graphic);
		static void any(std::reference_wrapper<IComponent> comp, IGraphic *graphic);
		static void sprites(std::vector<std::reference_wrapper<ISprite>> sprites, IGraphic *graphic);
		static void texts(std::vector<std::reference_wrapper<IText>> texts, IGraphic *graphic);
	};
}
#endif
