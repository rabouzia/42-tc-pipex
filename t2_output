SRC =	src/pipex.c				\
		src/mini_libft.c 		\
		src/mini_libft_dump.c	\
		src/cmd_exec.c


NAME =		pipex

CFLAGS =	-Wall -Werror -Wextra -g3 -I./inc

CC =		cc

OBJ = $(SRC:.c=.o)

all:		$(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus