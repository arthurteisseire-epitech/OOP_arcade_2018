/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SharedLibraryException.hpp
*/

#ifndef OOP_ARCADE_2018_SHAREDLIBRARYEXCEPTION_HPP
#define OOP_ARCADE_2018_SHAREDLIBRARYEXCEPTION_HPP

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
