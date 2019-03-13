/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MainMenu.hpp
*/

#ifndef ARCADE_MAINMENU_HPP
#define ARCADE_MAINMENU_HPP

#include <vector>
#include <memory>
#include "ISprite.hpp"
#include "Sprite.hpp"

namespace arc {
	class MainMenu {
	public:
		MainMenu();
		const std::vector<std::unique_ptr<ISprite>> &getSprites();
	private:
		void setSpritesPosition();
		void setSpritesSize();
		std::vector<std::unique_ptr<ISprite>> _sprites;
	};
}

#endif
