/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Widget.cpp
*/

#include <QPainter>
#include <QtWidgets/QApplication>
#include "Widget.hpp"

std::map<Qt::Key, arc::Key> arc::Widget::_qKeys = {
	{Qt::Key_Return, ENTER},
	{Qt::Key_Escape, ESCAPE},
	{Qt::Key_Up,     UP},
	{Qt::Key_Down,   DOWN},
	{Qt::Key_Left,   LEFT},
	{Qt::Key_Right,  RIGHT},
};

arc::Widget::Widget() :
	_text(nullptr)
{
}

void arc::Widget::paintEvent(__attribute((unused)) QPaintEvent *e)
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

bool arc::Widget::processSprite(const ISprite &sprite)
{
	QPixmap *pixmap;
	auto spriteSize = sprite.getSize();
	std::pair<int, int> pos;

	try {
		pixmap = _sprites.at(&sprite).get();
	} catch (const std::out_of_range &e) {
		pixmap = new QPixmap();
		if (!pixmap->load(QString::fromStdString(sprite.getTextureName())))
			return false;
		_sprites[&sprite] = std::unique_ptr<QPixmap>(pixmap);
	}
	pos.first = (int)(size().width() * spriteSize.first);
	pos.second = (int)(size().height() * spriteSize.second);
	*pixmap = pixmap->scaled(pos.first, pos.second);
	return true;
}

bool arc::Widget::processText(const IText &text)
{
	_text = &text;
	return true;
}

void arc::Widget::keyPressEvent(QKeyEvent *e)
{
	processKeys(e, PRESSED);
}

void arc::Widget::keyReleaseEvent(QKeyEvent *e)
{
	if (!e->isAutoRepeat())
		processKeys(e, RELEASED);
}

void arc::Widget::processKeys(const QKeyEvent *e, KeyState state)
{
	auto qtKey = static_cast<Qt::Key>(e->key());

	cleanKeys();
	try {
		Key key = _qKeys.at(qtKey);

		_keys[key] = state;
	} catch (const std::out_of_range &e) {
	}
}

void arc::Widget::cleanKeys()
{
	for (auto &it : _keys)
		if (it.second == PRESSED)
			it.second = HOLD;
}

std::map<arc::Key, arc::KeyState> arc::Widget::getKeys()
{
	auto tmp(_keys);

	auto it = _keys.begin();
	while (it != _keys.end())
		if (it->second == RELEASED)
			_keys.erase(it++);
		else
			++it;
	return tmp;
}
