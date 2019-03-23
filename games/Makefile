##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile
##

GAMES	=	nibbler	\
		qix	\

RULES	=	all		\
		clean		\
		fclean		\
		re		\
		debug		\

$(RULES):
	for module in $(GAMES); do\
		$(MAKE) --directory=$$module $@;\
	done

.PHONY: $(RULES)
