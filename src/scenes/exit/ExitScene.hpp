/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ExitScene.hpp
*/

#ifndef ARCADE_EXITSCENE_HPP
#define ARCADE_EXITSCENE_HPP

#include <memory>
#include "SharedData.hpp"
#include "Scene.hpp"

namespace arc {
	class ExitScene : public Scene {
	public:
		explicit ExitScene(const std::shared_ptr<SharedData> &playerData);

		void update(const std::map<arc::Key, arc::KeyState> &keys, float deltaTime) override;
		std::vector<std::reference_wrapper<const IComponent>> getComponents() const override;
		arc::SCENE nextScene(const std::map<Key, KeyState> &keys) const override;
	};
}

#endif
