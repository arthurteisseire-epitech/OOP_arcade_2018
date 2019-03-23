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
		explicit Core(const std::string &libname);
		int exec();
	private:
		void update(const std::map<Key, KeyState> &keys, float deltaTime);
		std::vector<std::string> scanLibraries(const std::string &libDir) const;
		std::string libPath();

		std::shared_ptr<SharedData> _sharedData;
		SceneManager _sceneManager;
		LibraryLoader _graphicLibraryLoader;
		LibraryLoader _gameLibraryLoader;
		std::unique_ptr<IGraphic> _graphic;
	};
}

#endif
