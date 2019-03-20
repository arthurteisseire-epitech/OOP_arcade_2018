/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** MainMenu.hpp
*/

#ifndef ARCADE_MAINMENU_HPP
#define ARCADE_MAINMENU_HPP

#include <vector>
#include <memory>
#include <map>
#include "Scene.hpp"
#include "IText.hpp"
#include "Text.hpp"
#include "ISprite.hpp"
#include "Sprite.hpp"
#include "Key.hpp"
#include "Button.hpp"
#include "Audio.hpp"

namespace arc {
	class MainMenu : public Scene {
	public:
		explicit MainMenu(const std::shared_ptr<SharedData> &playerData);
		void update(const std::map<Key, KeyState> &keys, float deltaTime) override;
		std::vector<std::reference_wrapper<IComponent>> getComponents() const override;
		SCENE nextScene() const override;
	private:
		void moveFocusDown();
		void moveFocusUp();
		void setSpritesPosition();
		void setSpritesSize();
		void fillComponents();

		std::unique_ptr<std::map<Key, KeyState>> _keys;
		std::vector<std::unique_ptr<Button>> _buttons;
		std::vector<std::unique_ptr<Audio>> _audios;
		std::unique_ptr<Sprite> _spriteFocus;
		std::unique_ptr<Text> _playerName;
		size_t _focus;
		static std::map<Key, void (arc::MainMenu::*)()> _keysMap;
		std::vector<std::reference_wrapper<IComponent>> _components;
	};
}

#endif
