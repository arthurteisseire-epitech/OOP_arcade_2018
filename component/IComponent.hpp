/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** IComponent.hpp
*/

#ifndef ARCADE_ICOMPONENT_HPP
#define ARCADE_ICOMPONENT_HPP

namespace arc {
	enum ComponentType {
		SPRITE,
		TEXT,
		SOUND
	};

	class IComponent {
	public:
		virtual ~IComponent() = default;

		/**
		 * @return The corresponding type from the enum ComponentType
		 */
		virtual ComponentType getType() const = 0;
	};
}

#endif
