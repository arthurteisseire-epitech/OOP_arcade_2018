##
## EPITECH PROJECT, 2018
## cpp_d01_2018
## File description:
## Makefile
##

CC		=	g++
DSRC	=	src/

MAIN	=	main.cpp
SRC		=	$(DSRC)library/LibraryLoader.cpp		\
			$(DSRC)library/LibraryException.cpp		\

SRC_UT	=	$(wildcard $(DSRC)*Test.cpp)				\
			$(wildcard $(DSRC)/library/*Test.cpp)		\

INC		=	-I$(DSRC)
CXXFLAGS	+=  -Wall -Wextra $(INC)
LDFLAGS	=	-lgtest -lgtest_main
OBJ		=	$(SRC:.cpp=.o) $(MAIN:.cpp=.o)
NAME	=	arcade
NAME_UT	=	units

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_UT)

re: fclean all

debug: CXXFLAGS += -g
debug: re

tests_run: CXXFLAGS += --coverage -ftest-coverage -fprofile-arcs -lgcov
tests_run:
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CXXFLAGS) $(LDFLAGS)
	./$(NAME_UT)
	gcov *.gcno &> /dev/null

tests_debug: CXXFLAGS += -g
tests_debug: tests_run

tests_clean:
	rm -f $(NAME_UT) *.gcno *.gcov *.gcda

.PHONY: all clean fclean re debug tests_run tests_debug tests_clean
