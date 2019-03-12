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
	QRect winRect = QApplication::activeWindow()->geometry();

	for (auto &_sprite : _sprites) {
		pos.first = (int)(winRect.width() * _sprite.first->getPosition().first);
		pos.second = (int)(winRect.height() * _sprite.first->getPosition().second);

		painter.drawPixmap(pos.first, pos.second, *_sprite.second);
	}
}

void Widget::processSprite(const ISprite &sprite)
{
	QPixmap *pixmap;
	auto size = sprite.getSize();

	try {
		pixmap = _sprites.at(&sprite).get();
	} catch (const std::out_of_range &e) {
		pixmap = new QPixmap(QString::fromStdString(sprite.getPath()));
		_sprites[&sprite] = std::unique_ptr<QPixmap>(pixmap);
	}
	*pixmap = pixmap->scaled((int)size.first, (int)size.second, Qt::IgnoreAspectRatio);
}
