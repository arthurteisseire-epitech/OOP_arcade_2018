/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Button.hpp
*/

#ifndef ARCADE_BUTTON_HPP
#define ARCADE_BUTTON_HPP

#include <memory>
#include "Sprite.hpp"

namespace arc {
	class Button : public Sprite {
	public:
		explicit Button(const std::string &filename);
	};
}

#endif
