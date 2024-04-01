SRC	  =		src/pipex.c					\
			src/mini_libft.c 			\
			src/mini_libft2.c 		\
			src/mini_libft_dump.c		\
			src/cmd_exec.c				\

BONUS =		bonus/pipex.c				\
			bonus/mini_libft.c 			\
			bonus/mini_libft2.c 		\
			bonus/mini_libft_dump.c		\
			bonus/cmd_exec.c			\
	


NAME =		pipex
NAME_BONUS =		pipex_bonus

CFLAGS =	-Wall -Werror -Wextra -g3 -I./inc

CC =		cc

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

all:		$(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^

$(NAME_BONUS): $(OBJ_BONUS)
		$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

bonus: $(NAME_BONUS)

re: fclean all

.PHONY: clean fclean all re bonus