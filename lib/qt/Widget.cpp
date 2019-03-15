/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Widget.cpp
*/

#include <QPainter>
#include <QtWidgets/QApplication>
#include <iostream>
#include "Widget.hpp"

std::map<Qt::Key, arc::Key> arc::Widget::_qKeys = {
	{Qt::Key_Return, ENTER},
	{Qt::Key_Up,     UP},
	{Qt::Key_Down,   DOWN},
	{Qt::Key_Left,   LEFT},
	{Qt::Key_Right,  RIGHT},
	{Qt::Key_F1,     F1},
	{Qt::Key_F2,     F2},
	{Qt::Key_F3,     F3},
	{Qt::Key_F4,     F4},
	{Qt::Key_Delete, SUPPR},
	{Qt::Key_Escape, ESCAPE},
	{Qt::Key_R,      R},
};

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
	for (auto text : _text) {
		textPos.setX((int)(size().width() * text->getPosition().first));
		textPos.setY((int)(size().height() * text->getPosition().second));
		painter.setFont(QFont("arial", text->getFontSize()));
		painter.drawText(textPos, QString::fromStdString(text->getText()));
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
	if (std::find(_text.begin(), _text.end(), &text) == _text.end())
		_text.push_back(&text);
	return true;
}

void arc::Widget::keyPressEvent(QKeyEvent *e)
{
	processKeys(e, PRESSED);
}

void arc::Widget::keyReleaseEvent(QKeyEvent *e)
{
	processKeys(e, RELEASED);
}

void arc::Widget::processKeys(const QKeyEvent *e, KeyState state)
{
	auto qtKey = static_cast<Qt::Key>(e->key());
	auto it = _qKeys.find(qtKey);

	if (it != _qKeys.end())
		_keys[it->second] = state;
}

void arc::Widget::updateKeysState()
{
	auto it = _keys.begin();

	while (it != _keys.end())
		if (it->second == RELEASED)
			_keys.erase(it++);
		else if (it->second == PRESSED) {
			it->second = HOLD;
			++it;
		} else
			++it;
}

const std::map<arc::Key, arc::KeyState> &arc::Widget::getKeys() const
{
	return _keys;
}
