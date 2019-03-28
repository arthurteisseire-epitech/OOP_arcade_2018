##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile
##

MODULES	=	core	\
		lib	\
		games	\

RULES	=	all		\
		clean		\
		fclean		\
		re		\

$(RULES):
	for module in $(MODULES); do\
		$(MAKE) --directory=$$module $@;\
	done

$(MODULES):
	$(MAKE) --directory=$@

graphicals:
	$(MAKE) --directory=lib

.PHONY: $(MODULES) $(RULES) graphicals
