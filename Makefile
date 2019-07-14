NAME	=	lem_in

CC		=	gcc -g
CFLAGS	=	-Wall -Wextra -Werror -Iincludes
DEBUG	=	-g -fsanitize=address

SRC		=	$(wildcard src/*.c)
OBJ		=	$(patsubst src/%.c, obj/%.o, $(SRC))

all		:	$(NAME)

obj/%.o	: 	src/%.c
			@$(CC) $(CFLAGS) $(OPTION) -c -o $@ $<

$(NAME)	:	obj $(OBJ)
			@cd lib && make
			@mv lib/libftprintf.a .
			@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) libftprintf.a
			@echo "excutable file $(NAME) has been made"

db		:	obj $(OBJ)
			@cd lib && make
			@mv lib/libftprintf.a .
			@$(CC) -o $(NAME) $(CFLAGS) $(DEBUG) $(OBJ) libftprintf.a
			@echo "excutable file $(NAME) with debug mode has been made"

obj		:
			@mkdir obj

clean	:
			-cd lib && make clean
			-rm -rf obj

fclean	:	clean
			-rm -f $(NAME)
			-rm -f libftprintf.a

re		:	fclean $(NAME)

.PHONY	:	clean fclean re
