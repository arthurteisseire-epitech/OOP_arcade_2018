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
	const std::string &getPath() const override;
	void setPosition(const std::pair<float, float> &pos);
private:
	std::string _filename;
	std::pair<float, float> _pos;
};

#endif
