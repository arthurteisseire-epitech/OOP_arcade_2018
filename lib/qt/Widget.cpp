/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Widget.cpp
*/

#include <QPainter>
#include "Widget.hpp"

void Widget::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);

	for (auto &_sprite : _sprites)
		painter.drawPixmap((int)_sprite.first->getPosition().first,
		(int)_sprite.first->getPosition().second,
		*_sprite.second);
}

void Widget::processSprite(const ISprite &sprite)
{
	try {
		_sprites.at(&sprite);
	} catch (const std::out_of_range &e) {
		auto pixmap = new QPixmap("assets/sample.jpg");
		auto size = sprite.getSize();
		QString path = QString::fromStdString(sprite.getPath());

		pixmap->load(path);
		pixmap->scaled((int)size.first, (int)size.second, Qt::KeepAspectRatio);
		_sprites[&sprite] = std::unique_ptr<QPixmap>(pixmap);
	}
}
