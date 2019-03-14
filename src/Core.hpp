/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.hpp
*/

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP

#include <memory>
#include "MainMenu.hpp"
#include "IGraphic.hpp"
#include "IGame.hpp"

namespace arc {
	class Core {
	public:
		explicit Core(IGraphic *graphic, IGame *game);
		int exec();
	private:
		std::unique_ptr<arc::MainMenu> _mainMenu;
		std::unique_ptr<IGraphic> _graphic;
		std::unique_ptr<IGame> _game;
	};
}

#endif