/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MainMenu.hpp
*/

#ifndef ARCADE_MAINMENU_HPP
#define ARCADE_MAINMENU_HPP

#include <vector>
#include "Sprite.hpp"

class MainMenu {
public:
	MainMenu();
	const Sprite &getSprite(size_t idx);
private:
	std::vector<Sprite> _sprites;
};

#endif
