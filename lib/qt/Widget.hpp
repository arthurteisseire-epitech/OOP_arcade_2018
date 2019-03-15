/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Widget.hpp
*/

#ifndef ARCADE_WIDGET_HPP
#define ARCADE_WIDGET_HPP

#include <memory>
#include <QWidget>
#include <QKeyEvent>
#include "IText.hpp"
#include "Key.hpp"
#include "ISprite.hpp"

namespace arc {
	class Widget : public QWidget {
	public:
		Widget() = default;
		bool processSprite(const ISprite &sprite);
		bool processText(const IText &text);
		std::map<Key, KeyState> getKeys();
	protected:
		void paintEvent(QPaintEvent *e) override;
		void keyPressEvent(QKeyEvent *e) override;
		void keyReleaseEvent(QKeyEvent *e) override;
	private:
		void processKeys(const QKeyEvent *e, arc::KeyState state);

		std::map<const ISprite *, std::unique_ptr<QPixmap>> _sprites;
		std::vector<const IText *> _text;
		std::map<Key, KeyState> _keys;
		static std::map<Qt::Key, Key> _qKeys;
	};
}

#endif
