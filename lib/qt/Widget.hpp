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

class Widget : public QWidget {
public:
	Widget();
	void processSprite(const ISprite &sprite);
	void processText(const IText &text);
	const std::vector<Key> &getKeys() const;
protected:
	void paintEvent(QPaintEvent *e) override;
	void keyPressEvent(QKeyEvent *e) override;
	void keyReleaseEvent(QKeyEvent *e) override;
private:
	std::map<const ISprite *, std::unique_ptr<QPixmap>> _sprites;
	const IText *_text;
	std::vector<Key> _keys;
};

#endif
