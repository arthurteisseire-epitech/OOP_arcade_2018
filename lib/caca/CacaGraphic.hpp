/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** CacaGraphic.cpp
*/


#ifndef ARCADE_CACAGRAPHIC_HPP
#define ARCADE_CACAGRAPHIC_HPP

#include <iostream>
#include <memory>
#include "IGraphic.hpp"
#include <caca_types.h>
#include <caca.h>

namespace arc {
	class CacaGraphic : public IGraphic {
		public:
		CacaGraphic();
		bool isOpen() const override;
		void draw() override;
		bool processSprite(const ISprite &sprite) override;
		bool processText(const IText &text) override;
		bool processAudio(const IAudio &audio) override;
		void processEvents() override;
		const std::map<Key, KeyState> &getKeys() const override;
		std::pair<unsigned, unsigned> getWindowSize() const override;
		int getWidth();
		int getHeight();
		private:
		void updateKeysState();
		void processKey(arc::KeyState keyState, caca_event_t);
		caca_canvas_t *_cv;
		caca_display_t *_dp;
		bool _isOpen;
		static std::map<caca_key, Key> _cKeys;
		std::map<arc::Key, arc::KeyState> _Keys;
	};
}
extern "C" __attribute__((visibility("default"))) arc::IGraphic *graphicEntryPoint();


#endif //ARCADE_CACAGRAPHIC_HPP
