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
		static void sprites(const std::vector<std::reference_wrapper<const ISprite>> &sprites, IGraphic *graphic);
		static void texts(const std::vector<std::reference_wrapper<const IText>> &texts, IGraphic *graphic);
		static void audios(const std::vector<std::reference_wrapper<const IAudio>> &audios, IGraphic *graphic);
		static void components(const std::vector<std::reference_wrapper<const IComponent>> &components,
		                       arc::IGraphic *graphic);
	};
}
#endif
