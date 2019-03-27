##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile
##

CC	=	g++
DSRC	=	src/
DLIB	=	$(DSRC)library/
DSCN	=	$(DSRC)scenes/
DCOMP	=	../component/

INC	=	-I$(DCOMP)		\
		-I../games		\
		-I../lib		\
		-I$(DSRC)		\
		-I$(DLIB)		\
		-I$(DSCN)		\
		-I$(DSCN)exit		\
		-I$(DSCN)game		\
		-I$(DSCN)menu		\
		-I$(DSCN)player_name	\
		-I$(DSCN)utils		\

SRC	=	$(wildcard $(DSRC)*.cpp)		\
		$(wildcard $(DLIB)*.cpp)		\
		$(wildcard $(DSCN)*.cpp)		\
		$(wildcard $(DSCN)exit/*.cpp)		\
		$(wildcard $(DSCN)game/*.cpp)		\
		$(wildcard $(DSCN)menu/*.cpp)		\
		$(wildcard $(DSCN)player_name/*.cpp)	\
		$(wildcard $(DSCN)utils/*.cpp)		\
		$(wildcard $(DCOMP)*.cpp)		\

CXXFLAGS=	-Wall -Wextra $(INC) -std=c++14 -O2
LDFLAGS	=	-ldl
OBJ	=	$(SRC:.cpp=.o)
NAME	=	arcade

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS)
	mv $(NAME) ..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all


.PHONY: all clean fclean re
