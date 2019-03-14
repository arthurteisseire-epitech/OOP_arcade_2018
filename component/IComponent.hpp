/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** IComponent.hpp,
*/

#ifndef ARCADE_ICOMPONENT_HPP
#define ARCADE_ICOMPONENT_HPP

enum ComponentType{SPRITE, TEXT, SOUND};

class IComponent {
public:
	virtual ~IComponent() = default;

	virtual ComponentType getType() const = 0;
};

#endif
