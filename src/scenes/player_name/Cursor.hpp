/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Cursor.hpp
*/

#ifndef ARCADE_CURSOR_HPP
#define ARCADE_CURSOR_HPP

#include "Text.hpp"
#include "Sprite.hpp"

namespace arc {
	class Cursor : public Sprite {
	public:
		explicit Cursor(Text *letter);
	private:
		Text *_letter;
	};
}

#endif
