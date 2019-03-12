/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Widget.cpp
*/

#include <QPainter>
#include "Widget.hpp"

void Widget::paintEvent(__attribute((unused)) QPaintEvent *e)
{
	QPainter painter(this);

	for (auto &_sprite : _sprites)
		painter.drawPixmap((int)_sprite.first->getPosition().first,
		(int)_sprite.first->getPosition().second,
		*_sprite.second);
}

void Widget::processSprite(const ISprite &sprite)
{
	QPixmap *pixmap;
	auto size = sprite.getSize();

	try {
		pixmap = _sprites.at(&sprite).get();
	} catch (const std::out_of_range &e) {
		QString path = QString::fromStdString(sprite.getPath());
		pixmap = new QPixmap(path);
		_sprites[&sprite] = std::unique_ptr<QPixmap>(pixmap);
	}
	*pixmap = pixmap->scaled((int)size.first, (int)size.second, Qt::IgnoreAspectRatio);
}
