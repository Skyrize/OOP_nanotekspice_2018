##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

SRC	=	src/main.cpp								\
		src/NanoError.cpp							\
		src/Factory.cpp								\
		src/Circuit.cpp								\
		src/Parser.cpp								\
													\
													\
		src/component/chipset/Component.cpp			\
		src/component/chipset/Component2716.cpp		\
		src/component/chipset/Component4001.cpp		\
		src/component/chipset/Component4008.cpp		\
		src/component/chipset/Component4011.cpp		\
		src/component/chipset/Component4013.cpp		\
		src/component/chipset/Component4017.cpp		\
		src/component/chipset/Component4030.cpp		\
		src/component/chipset/Component4040.cpp		\
		src/component/chipset/Component4069.cpp		\
		src/component/chipset/Component4071.cpp		\
		src/component/chipset/Component4081.cpp		\
		src/component/chipset/Component4094.cpp		\
		src/component/chipset/Component4514.cpp		\
		src/component/chipset/Component4801.cpp		\
													\
													\
		src/component/special/Clock.cpp				\
		src/component/special/False.cpp				\
		src/component/special/Input.cpp				\
		src/component/special/Output.cpp			\
		src/component/special/True.cpp				\
													
		
		

OBJS	=	$(SRC:.cpp=.o)

NAME	=	nanotekspice

CXXFLAGS	=	 -Wall -Wextra -Werror

CC	=	g++ -I./include/ -I./include/component/chipset/ -I./include/component/special/ --std=c++11 -g

_END=$'\x1b[0m'
_RED=$'\x1b[31m'
NO_OF_FILES := $(words $(SRC))

all:	$(NAME)

$(NAME):	$(OBJS)
	@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;35m$(NO_OF_FILES)\033[0m"
	$(CC) -o $(NAME) $(OBJS) $(CXXFLAGS)
	@ echo "\033[1;31m ------------------Name of Binary : \033[1;35m$(NAME)\033[0;31m®\033[1;31m Created Sucesfully ------------------\033[0m"

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

%.o:	%.cpp
	@ echo "\033[1;35m[ OK ]\033[0m Compiling" $<
	@ $(CC) -o $@ -c $< $(CFLAGS)

.SILENT:
