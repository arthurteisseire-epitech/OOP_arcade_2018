/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Core.hpp
*/

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP


#include <memory>
#include "LibraryManager.hpp"
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
		void processEvents(const std::map<arc::Key, arc::KeyState> &keys);
		void updateSharedData();

		void backToMenu();
		void exit();
		void reloadGame();
		void prevGraphicalLib();
		void nextGraphicalLib();
		void prevGameLib();
		void nextGameLib();
		float calcDeltaTime() const;

		std::shared_ptr<SharedData> _sharedData;
		SceneManager _sceneManager;
		LibraryManager<IGame> _gameManager;
		LibraryManager<IGraphic> _graphicManager;

		static const std::map<Key, void (arc::Core::*)()> _keyAction;
		static const std::string GRAPHIC_DIR;
		static const std::string GAME_DIR;
		static const std::string GRAPHIC_ENTRY_POINT;
		static const std::string GAME_ENTRY_POINT;
	};
}

#endif
