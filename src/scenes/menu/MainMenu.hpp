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
		MainMenu();
		std::vector<std::reference_wrapper<ISprite>> getSprites() const override;
		std::vector<std::reference_wrapper<IText>> getTexts() const override;
		std::vector<std::reference_wrapper<IAudio>> getAudios() const override;
		void processEvents(const std::map<Key, KeyState> &keys) override;
		SCENE nextScene() const override;
	private:
		void moveFocusDown();
		void moveFocusUp();
		void setSpritesPosition();
		void setSpritesSize();

		size_t _focus;
		std::unique_ptr<std::map<Key, KeyState>> _keys;
		std::vector<std::unique_ptr<Button>> _buttons;
		std::vector<std::unique_ptr<Audio>> _audios;
		std::unique_ptr<Sprite> _spriteFocus;
		static std::map<Key, void (arc::MainMenu::*)()> _keysMap;
	};
}

#endif
