/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** LibraryLoaderException.hpp
*/

#ifndef OOP_ARCADE_2018_LIBRARYLOADEREXCEPTION_HPP
#define OOP_ARCADE_2018_LIBRARYLOADEREXCEPTION_HPP

#include <string>

class SharedLibraryException : public std::exception {
public:
	explicit SharedLibraryException(const std::string &message);
	~SharedLibraryException() override = default;
	char const *what() const noexcept override;
private:
	const std::string _message;
};

#endif
