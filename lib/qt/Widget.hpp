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
#include "ISprite.hpp"

class Widget : public QWidget {
public:
	Widget() = default;
	void processSprite(const ISprite &sprite);
protected:
	void paintEvent(QPaintEvent *e) override;
private:
	std::map<const ISprite *, std::unique_ptr<QPixmap>> _sprites;
};
#endif
