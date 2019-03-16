/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.hpp
*/

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP

#include <memory>
#include "Scenes.hpp"
#include "MainMenu.hpp"
#include "IGraphic.hpp"
#include "IGame.hpp"

namespace arc {
	class Core {
	public:
		explicit Core(IGraphic *graphic);
		int exec();
	private:
		std::unique_ptr<Scenes> _scenes;
		std::unique_ptr<IGraphic> _graphic;
		std::unique_ptr<IGame> _game;
	};
}

#endif
