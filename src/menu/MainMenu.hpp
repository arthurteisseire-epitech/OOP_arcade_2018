/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MainMenu.hpp
*/

#ifndef ARCADE_MAINMENU_HPP
#define ARCADE_MAINMENU_HPP

#include <vector>
#include "ASprite.hpp"

class MainMenu {
public:
	void loadSprites();
private:
	std::vector<ASprite> _sprites;
};

#endif
