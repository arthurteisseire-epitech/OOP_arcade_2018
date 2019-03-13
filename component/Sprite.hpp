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

class Sprite : public ISprite {
public:
	explicit Sprite(const std::string &filename);
	~Sprite() override = default;

	ComponentType getType() const final;
	const std::string &getPath() const override;
	void setPosition(const std::pair<float, float> &pos);
	void setSize(const std::pair<float, float> &size);
	const std::pair<float, float> &getPosition() const override;
	const std::pair<float, float> &getSize() const override;
private:
	std::string _filename;
	std::pair<float, float> _pos;
	std::pair<float, float> _size;
};

#endif
