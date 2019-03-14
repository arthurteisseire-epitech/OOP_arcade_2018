/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Created by abel,
*/

#ifndef ARCADE_KEY_HPP
#define ARCADE_KEY_HPP

#include <string>

namespace arc {

    enum Key {
            UP,
            DOWN,
            RIGHT,
            LEFT,
            ENTER,
            ESCAPE, /* back to menu */
            SUPPR,  /* exit game */
            F1, /* previous game */
            F2, /* next game */
            F3, /* previous graphic library */
            F4, /* next graphic library */
            R   /* restart game */
    };

    enum KeyState {
        PRESSED,
        HOLD,
        RELEASED
    };
}

#endif //ARCADE_KEY_HPP
