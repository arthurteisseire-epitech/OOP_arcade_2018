/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** CacaGraphic.cpp
*/

#include "CacaGraphic.hpp"
#include <caca_types.h>
#include <caca.h>
#include <Imlib2.h>

std::map<caca_key, arc::Key> arc::CacaGraphic::_cKeys = {
	{CACA_KEY_RETURN, arc::ENTER},
	{CACA_KEY_UP,     arc::UP},
	{CACA_KEY_DOWN,   arc::DOWN},
	{CACA_KEY_LEFT,   arc::LEFT},
	{CACA_KEY_RIGHT,  arc::RIGHT},
	{CACA_KEY_F1,     arc::F1},
	{CACA_KEY_F2,     arc::F2},
	{CACA_KEY_F3,     arc::F3},
	{CACA_KEY_F4,     arc::F4},
	{CACA_KEY_DELETE, arc::SUPPR},
	{CACA_KEY_ESCAPE, arc::ESCAPE},
};


arc::IGraphic *graphicEntryPoint()
{
	return new arc::CacaGraphic();
}

arc::CacaGraphic::CacaGraphic() :
	_cv(caca_create_canvas(160, 30)),
	_dp(caca_create_display(_cv)),
	_isOpen(true)
{

	caca_create_display(_cv);
	_cv = caca_get_canvas(_dp);
	caca_set_display_title(_dp, "Arcade");
	caca_set_color_ansi(_cv, CACA_WHITE, CACA_BLACK);
}


void arc::CacaGraphic::draw()
{
	caca_refresh_display(_dp);
	caca_clear_canvas(_cv);
}

bool arc::CacaGraphic::isOpen() const
{
	return _isOpen;
}

bool arc::CacaGraphic::processSprite(const arc::ISprite &sprite)
{
	Imlib_Image image = imlib_load_image(sprite.getTextureName().c_str());
	if (image == nullptr) {
		std::cerr << "imlib_load_image: Cannot load " << sprite.getTextureName().c_str() << std::endl;
		return false;
	}
	imlib_context_set_image(image);

	std::cout << (int)(sprite.getPosition().first * imlib_image_get_width()) << std::endl
		<< (int)(sprite.getPosition().second * imlib_image_get_height()) << std::endl
		<< (int)(sprite.getSize().first * imlib_image_get_width()) << std::endl
		<< (int)(sprite.getSize().second * imlib_image_get_height()) << std::endl;

	caca_dither_bitmap(_cv,
		(int)(sprite.getPosition().first * imlib_image_get_width()),
		(int)(sprite.getPosition().second * imlib_image_get_height()),
		(int)(sprite.getSize().first * imlib_image_get_width()),
		(int)(sprite.getSize().second * imlib_image_get_height()),
		caca_create_dither(32, imlib_image_get_width(), imlib_image_get_height(), 4 * imlib_image_get_width(), 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000),
		imlib_image_get_data_for_reading_only()
		);

	return true;
}

bool arc::CacaGraphic::processText(const arc::IText &text)
{
	caca_put_str(_cv, (unsigned)(text.getPosition().first * getWidth()), (unsigned)(text.getPosition().second * getHeight()), (char *)text.getText().c_str());
	return true;
}

bool arc::CacaGraphic::processAudio(const arc::IAudio &audio)
{
	(void)audio;
	return false;
}

void arc::CacaGraphic::processEvents()
{
	caca_event_t event;

	updateKeysState();
	caca_get_event(_dp, CACA_EVENT_ANY, &event, 1);

	if (event.type == CACA_EVENT_KEY_PRESS)
		processKey(PRESSED, event);
	else if (event.type == CACA_EVENT_KEY_RELEASE)
		processKey(RELEASED, event);
	else if (event.type == CACA_EVENT_QUIT) {
		_isOpen = false;
	}

}

void arc::CacaGraphic::processKey(arc::KeyState keyState, caca_event_t event)
{
	auto it = _cKeys.find((caca_key)caca_get_event_key_ch(&event));
	if (it != _cKeys.end()) {
		auto key = _Keys.find(it->second);
		if (!(key != _Keys.end() && keyState == PRESSED))
			_Keys[it->second] = keyState;
	}
}

const std::map<arc::Key, arc::KeyState> &arc::CacaGraphic::getKeys() const
{
	return _Keys;
}

void arc::CacaGraphic::updateKeysState()
{
	auto it = _Keys.begin();

	while (it != _Keys.end())
		if (it->second == RELEASED)
			_Keys.erase(it++);
		else if (it->second == PRESSED) {
			it->second = HOLD;
			++it;
		} else
			++it;
}

std::pair<unsigned, unsigned> arc::CacaGraphic::getWindowSize() const
{
	return {(unsigned)caca_get_display_width(_dp), (unsigned)caca_get_display_height(_dp)};
}

int arc::CacaGraphic::getWidth()
{
	return caca_get_canvas_width(_cv);
}

int arc::CacaGraphic::getHeight()
{
	return caca_get_canvas_height(_cv);
}