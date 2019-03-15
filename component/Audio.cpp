/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Audio.cpp
*/

#include "Audio.hpp"

int arc::Audio::getVolume() const
{
        return _volume;
}

const std::string &arc::Audio::getSoundPath() const
{
        return _path;
}

void arc::Audio::setVolume(int volume)
{
        _volume = volume;
}

void arc::Audio::setPath(const std::string &path)
{
        _path = path;
}
