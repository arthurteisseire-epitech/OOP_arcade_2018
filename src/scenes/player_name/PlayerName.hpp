/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** PlayerName.hpp
*/

#ifndef ARCADE_PLAYERNAME_HPP
#define ARCADE_PLAYERNAME_HPP

#include <memory>
#include "Scene.hpp"
#include "Text.hpp"
#include "Cursor.hpp"
#include "Row.hpp"

namespace arc {
	class PlayerName : public Scene {
	public:
		explicit PlayerName(const std::shared_ptr<PlayerData> &playerData);
		std::vector<std::reference_wrapper<ISprite>> getSprites() const override;
		std::vector<std::reference_wrapper<IText>> getTexts() const override;
		std::vector<std::reference_wrapper<IAudio>> getAudios() const override;
		void processEvents(const std::map<Key, KeyState> &keys) override;
		SCENE nextScene() const override;
	private:
		void moveFocusLeft();
		void moveFocusRight();
		void moveFocusUp();
		void moveFocusDown();
		void action();
		bool in(int x, int y) const;
		Text *getFocus() const;

		std::unique_ptr<std::map<Key, KeyState>> _keys;
		std::unique_ptr<Text> _playerText;
		std::vector<Row> _gridLetters;
		std::unique_ptr<Cursor> _cursor;
		std::pair<int, int> _focus;
		static const int FONT_SIZE;
		static const std::string PREFIX;
		static const std::map<Key, void (arc::PlayerName::*)()> _keysMap;
	};
}

#endif
