/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.hpp
*/

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP

#include <memory>
#include "SceneManager.hpp"
#include "MainMenu.hpp"
#include "IGraphic.hpp"
#include "IGame.hpp"

namespace arc {
	class Core {
	public:
		explicit Core(IGraphic *graphic, std::unique_ptr<LibraryLoader> libraryLoader);
		int exec();
	private:
		void update(const std::map<Key, KeyState> &keys, float deltaTime);

		std::shared_ptr<PlayerData> _playerData;
		std::unique_ptr<SceneManager> _sceneManager;
		std::unique_ptr<LibraryLoader> _graphicLibraryLoader;
		std::unique_ptr<LibraryLoader> _gameLibraryLoader;
		std::unique_ptr<IGraphic> _graphic;
	};
}

#endif
