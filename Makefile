CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c src/pipex.c src/utils.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -Iincludes -Ilibft
LIBFT = libft/libft.a

NAME = pipex

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all