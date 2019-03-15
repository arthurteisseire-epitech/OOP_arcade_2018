/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ISprite.hpp
*/

#ifndef ARCADE_SPRITE_HPP
#define ARCADE_SPRITE_HPP

#include <string>
#include "ISprite.hpp"

namespace arc {
	class Sprite : public ISprite {
	public:
		explicit Sprite(const std::string &filename);
		~Sprite() override = default;

		ComponentType getType() const final;
		const std::string &getTextureName() const override;
		const std::pair<float, float> &getPosition() const override;
		const std::pair<float, float> &getSize() const override;
		void setPosition(const std::pair<float, float> &pos);
		unsigned int getColor() const override;
		void setSize(const std::pair<float, float> &size);
		void moveUp(float y);
		void moveDown(float y);
	private:
		std::string _filename;
		std::pair<float, float> _pos;
		std::pair<float, float> _size;
		unsigned int _color;
	};
}

#endif
