/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** LibraryLoaderException.hpp
*/

#ifndef ARCADE_LIBRARYLOADEREXCEPTION_HPP
#define ARCADE_LIBRARYLOADEREXCEPTION_HPP

#include <string>

namespace arc {
	class LibraryLoaderException : public std::exception {
	public:
		explicit LibraryLoaderException(const std::string &message);
		~LibraryLoaderException() override = default;
		char const *what() const noexcept override;
	private:
		const std::string _message;
	};
}

#endif
