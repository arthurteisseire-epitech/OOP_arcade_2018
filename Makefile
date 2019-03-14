##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile
##

RULES	=	all		\
		clean		\
		fclean		\
		re		\
		tests_run	\

$(RULES):
	cmake . && $(MAKE) $@

.PHONY: $(RULES)