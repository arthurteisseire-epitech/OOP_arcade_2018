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
		static void sprites(const std::vector<std::reference_wrapper<ISprite>> &sprites, IGraphic *graphic);
		static void texts(const std::vector<std::reference_wrapper<IText>> &texts, IGraphic *graphic);
		static void audios(const std::vector<std::reference_wrapper<IAudio>> &audios, IGraphic *graphic);
	};
}
#endif
