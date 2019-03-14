/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Widget.cpp
*/

#include <QPainter>
#include <QtWidgets/QApplication>
#include "Widget.hpp"

Widget::Widget() :
	_text(nullptr)
{
}

static std::map<Qt::Key, Key> Keys = {
	{Qt::Key_Return, ENTER},
	{Qt::Key_Enter,  ENTER},
	{Qt::Key_Escape, ESCAPE},
	{Qt::Key_Up,     UP},
	{Qt::Key_Down,   DOWN},
	{Qt::Key_Left,   LEFT},
	{Qt::Key_Right,  RIGHT},
};

void Widget::paintEvent(__attribute((unused)) QPaintEvent *e)
{
	QPainter painter(this);
	QPoint spritePos;
	QPoint textPos;

	for (auto &_sprite : _sprites) {
		spritePos.setX((int)(size().width() * _sprite.first->getPosition().first));
		spritePos.setY((int)(size().height() * _sprite.first->getPosition().second));
		painter.drawPixmap(spritePos, *_sprite.second);
	}
	if (_text != nullptr) {
		textPos.setX((int)(size().width() * _text->getPosition().first));
		textPos.setY((int)(size().height() * _text->getPosition().second));
		painter.setFont(QFont("arial", _text->getFontSize()));
		painter.drawText(textPos, QString::fromStdString(_text->getText()));
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

void Widget::processText(const IText &text)
{
	_text = &text;
}

void Widget::keyPressEvent(QKeyEvent *e)
{
	auto qtKey = static_cast<Qt::Key>(e->key());

	try {
		Key key = Keys.at(qtKey);

		if (std::find(_keys.begin(), _keys.end(), key) == _keys.end())
			_keys.push_back(key);
	} catch (const std::out_of_range &e) {
	}
}

void Widget::keyReleaseEvent(QKeyEvent *e)
{
	auto qtKey = static_cast<Qt::Key>(e->key());

	try {
		auto it = std::find(_keys.begin(), _keys.end(), Keys.at(qtKey));

		if (it != _keys.end())
			_keys.erase(it);
	} catch (const std::out_of_range &e) {
	}
}

const std::vector<Key> &Widget::getKeys() const
{
	return _keys;
}
