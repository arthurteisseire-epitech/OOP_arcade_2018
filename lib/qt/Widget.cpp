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

	for (auto &_sprite : _sprites) {
		pos.first = (int)(size().width() * _sprite.first->getPosition().first);
		pos.second = (int)(size().height() * _sprite.first->getPosition().second);

		painter.drawPixmap(pos.first, pos.second, *_sprite.second);
	}
}

void Widget::processSprite(const ISprite &sprite)
{
	QPixmap *pixmap;
	auto spriteSize = sprite.getSize();
	std::pair<int, int> pos;

	try {
		pixmap = _sprites.at(&sprite).get();
	} catch (const std::out_of_range &e) {
		pixmap = new QPixmap(QString::fromStdString(sprite.getPath()));
		_sprites[&sprite] = std::unique_ptr<QPixmap>(pixmap);
	}
	pos.first = (int)(size().width() * spriteSize.first);
	pos.second = (int)(size().height() * spriteSize.second);
	*pixmap = pixmap->scaled(pos.first, pos.second);
}

void Widget::keyPressEvent(QKeyEvent *e)
{
	if (e->key() == Qt::Key_Return)
		_key.push_back(ENTER);
}

void Widget::keyReleaseEvent(QKeyEvent *e)
{
	auto it = std::find(_key.begin(), _key.end(), ENTER);

	if (e->key() == Qt::Key_Return) {
		if (it != _key.end())
			_key.erase(std::find(_key.begin(), _key.end(), ENTER));
	}
}
