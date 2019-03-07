/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** LibraryLoaderException.hpp
*/

#ifndef OOP_ARCADE_2018_LIBRARYLOADEREXCEPTION_HPP
#define OOP_ARCADE_2018_LIBRARYLOADEREXCEPTION_HPP

#include <string>

class LibraryLoaderException : public std::exception {
public:
	explicit LibraryLoaderException(const std::string &message);
	~LibraryLoaderException() override = default;
	char const *what() const noexcept override;
private:
	const std::string _message;
};

#endif
