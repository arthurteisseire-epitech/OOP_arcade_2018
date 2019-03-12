/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Widget.cpp
*/

#include <QPainter>
#include <QtWidgets/QApplication>
#include "Widget.hpp"

void Widget::paintEvent(__attribute((unused)) QPaintEvent *e)
{
	QPainter painter(this);
	std::pair<int, int> pos;
	QSize winSize = QApplication::activeWindow()->size();

	for (auto &_sprite : _sprites) {
		pos.first = (int)(winSize.width() * _sprite.first->getPosition().first);
		pos.second = (int)(winSize.height() * _sprite.first->getPosition().second);

		painter.drawPixmap(pos.first, pos.second, *_sprite.second);
	}
}

void Widget::processSprite(const ISprite &sprite)
{
	QPixmap *pixmap;
	auto size = sprite.getSize();
	std::pair<int, int> pos;
	QSize winSize = QApplication::activeWindow()->size();

	try {
		pixmap = _sprites.at(&sprite).get();
	} catch (const std::out_of_range &e) {
		pixmap = new QPixmap(QString::fromStdString(sprite.getPath()));
		_sprites[&sprite] = std::unique_ptr<QPixmap>(pixmap);
	}
	pos.first = (int)(winSize.width() * size.first);
	pos.second = (int)(winSize.height() * size.second);
	*pixmap = pixmap->scaled(pos.first, pos.second);
}
