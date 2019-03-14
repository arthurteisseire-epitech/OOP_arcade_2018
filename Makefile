##
## EPITECH PROJECT, 2017
## File Name : Makefile
## File description:
## Project Name : linked_lists
##

RULES	=	all		\
		clean		\
		fclean		\
		re		\
		test_run	\

$(RULES):
	cmake . && $(MAKE) $@

.PHONY: $(RULES)
