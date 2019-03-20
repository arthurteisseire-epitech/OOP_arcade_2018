/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SceneManager.hpp
*/

#ifndef ARCADE_SCENEMANAGER_HPP
#define ARCADE_SCENEMANAGER_HPP

#include <map>
#include <memory>
#include "LibraryLoader.hpp"
#include "IGraphic.hpp"
#include "IScene.hpp"
#include "SceneFactory.hpp"
#include "Scenes.hpp"

namespace arc {
	class SceneManager {
	public:
		explicit SceneManager(SCENE scene, std::unique_ptr<LibraryLoader> libraryLoader, IGraphic *graphic);
		~SceneManager() = default;

		void changeScene(SCENE scene);
		IScene &currentScene() const;
		int start();
	protected:
		SCENE _currScene;
		std::unique_ptr<SceneFactory> _factory;
		std::map<SCENE, std::unique_ptr<IScene>> _scene;
		std::shared_ptr<PlayerData> _playerData;
		std::unique_ptr<LibraryLoader> _libraryLoader;
		std::unique_ptr<IGraphic> _graphic;
	};
}

#endif
