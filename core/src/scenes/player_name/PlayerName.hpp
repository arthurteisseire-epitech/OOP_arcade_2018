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
		explicit PlayerName(const std::shared_ptr<SharedData> &playerData);
		void update(const std::map<Key, KeyState> &keys, float deltaTime) override;
		std::vector<std::reference_wrapper<const IComponent>> getComponents() const override;
		arc::SCENE nextScene(const std::map<Key, KeyState> &keys) const override;
	private:
		void moveFocusLeft();
		void moveFocusRight();
		void moveFocusUp();
		void moveFocusDown();
		void action();
		bool in(int x, int y) const;
		Text *getFocus() const;

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
