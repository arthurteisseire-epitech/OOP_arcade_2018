##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile
##

all:
	cd qt && qmake && make install
	cd sfml && make
	cd caca && make

fclean:
	cd qt && qmake && make distclean
	cd sfml && make $@
	cd caca && make $@

re:
	cd qt && qmake && make distclean && qmake && make
	cd sfml && make $@
	cd caca && make $@

clean:
	cd qt && qmake && make $@
	cd sfml && make $@
	cd caca && make $@

.PHONY: all fclean re clean
