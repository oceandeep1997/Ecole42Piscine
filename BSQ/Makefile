NAME = bsq

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src
SRC = $(addprefix $(SRC_DIR)/, ft_find_largest_square.c ft_print_map.c ft_read_map.c main.c ft_putstr.c ft_read_map_from_stdin.c ft_print_error.c ft_putchar.c ft_read_map_data.c ft_file_operation.c)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)
clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all