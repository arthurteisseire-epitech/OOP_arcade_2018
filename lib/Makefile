##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile
##

all:
	cd qt && qmake && make install
	cd sfml && make

fclean:
	cd qt && qmake && make distclean
	cd sfml && make fclean

re:
	cd qt && qmake && make distclean && qmake && make
	cd sfml && make re

clean:
	cd qt && qmake && make $@
	cd sfml && make $@

.PHONY: all fclean re clean
