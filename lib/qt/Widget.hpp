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
#include "Key.hpp"
#include "ISprite.hpp"

class Widget : public QWidget {
public:
	Widget() = default;
	void processSprite(const ISprite &sprite);
protected:
	void paintEvent(QPaintEvent *e) override;
	void keyPressEvent(QKeyEvent *e) override;
	void keyReleaseEvent(QKeyEvent *e) override;
private:
	std::map<const ISprite *, std::unique_ptr<QPixmap>> _sprites;
	std::vector<Key> _key;
};
#endif
