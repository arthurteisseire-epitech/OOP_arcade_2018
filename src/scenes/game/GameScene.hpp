/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** GameScene.hpp
*/

#ifndef ARCADE_GAMESCENE_HPP
#define ARCADE_GAMESCENE_HPP

#include "Scene.hpp"

namespace arc {
	class GameScene : public Scene {
	public:
		explicit GameScene(const std::shared_ptr<SharedData> &playerData);

		void update(const std::map<arc::Key, arc::KeyState> &keys, float deltaTime) override;
		std::vector<std::reference_wrapper<IComponent>> getComponents() const override;
		SCENE nextScene() const override;
	};
}

#endif
