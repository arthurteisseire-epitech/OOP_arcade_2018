/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** IScene.hpp
*/

#ifndef ARCADE_SCENE_HPP
#define ARCADE_SCENE_HPP

#include <vector>
#include <map>
#include "ISprite.hpp"
#include "IText.hpp"
#include "IAudio.hpp"
#include "Key.hpp"

namespace arc {
	class IScene {
	public:
                virtual ~IScene() = default;
		virtual std::vector<std::reference_wrapper<ISprite>> getSprites() const = 0;
		virtual std::vector<std::reference_wrapper<IText>> getTexts() const = 0;
		virtual std::vector<std::reference_wrapper<IAudio>> getAudios() const = 0;
		virtual void processEvents(const std::map<Key, KeyState> &map) = 0;
	};
}

#endif
