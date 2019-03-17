/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Widget.cpp
*/

#include <QPainter>
#include <QtWidgets/QApplication>
#include <QtGui/QFontDatabase>
#include <QtCore/QFileInfo>
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

void arc::Widget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QPoint spritePos;
	QPoint textPos;

	for (auto &_sprite : _spritesToDraw) {
		spritePos.setX((int)(size().width() * _sprite.first->getPosition().first));
		spritePos.setY((int)(size().height() * _sprite.first->getPosition().second));
		painter.drawPixmap(spritePos, _sprite.second);
	}
	for (auto text : _textsToDraw) {
		textPos.setX((int)(size().width() * text->getPosition().first));
		textPos.setY((int)(size().height() * text->getPosition().second));
		painter.setFont(QFont(QString::fromStdString(text->getFontPath()), text->getFontSize()));
		painter.drawText(textPos, QString::fromStdString(text->getText()));
	}
	_spritesToDraw.clear();
	_textsToDraw.clear();
}

bool arc::Widget::processSprite(const ISprite &sprite)
{
	auto it = _sprites.find(&sprite);
	QPixmap *pixmap = it->second.get();
	std::pair<int, int> pos((int)(size().width() * sprite.getSize().first),
	                        (int)(size().height() * sprite.getSize().second));

	if (it == _sprites.end()) {
		pixmap = new QPixmap(QString::fromStdString(sprite.getTextureName()));
		if (pixmap->isNull()) {
			delete pixmap;
			pixmap = new QPixmap(pos.first, pos.second);
			pixmap->fill(QColor((sprite.getColor() & 0x000000ff),
			                    (sprite.getColor() & 0x0000ff00) >> 8,
			                    (sprite.getColor() & 0x00ff0000) >> 16,
			                    (sprite.getColor() & 0xff000000) >> 24));
		}
		_sprites.emplace(&sprite, std::unique_ptr<QPixmap>(pixmap));
	}
	*pixmap = pixmap->scaled(pos.first, pos.second);
	_spritesToDraw.emplace(&sprite, *pixmap);
	return true;
}

bool arc::Widget::processText(const IText &text)
{
	if (std::find(_texts.begin(), _texts.end(), &text) == _texts.end()) {
		QFontDatabase::addApplicationFont(QString::fromStdString(text.getFontPath()));
		_texts.push_back(&text);
	}
	_textsToDraw.push_back(&text);
	return true;
}

bool arc::Widget::processAudio(const arc::IAudio &audio)
{
	QString path(QString::fromStdString(audio.getSoundPath()));
	QFileInfo file(path);
	auto player = new QMediaPlayer();

	if (_player.find(&audio) == _player.end()) {
		if (!file.exists())
			return false;
		player->setMedia(QUrl::fromLocalFile(file.absoluteFilePath()));
		_player[&audio] = std::unique_ptr<QMediaPlayer>(player);
	}
	player->setVolume(audio.getVolume());
	player->play();
	return true;
}

void arc::Widget::keyPressEvent(QKeyEvent *e)
{
	if (!e->isAutoRepeat())
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
