NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = mlxopengl

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = cub3d.h

B_HEADER = cub3d_bonus.h

SRC = cub3d \
	parse \
	parse_map \
	parse_tools \
	parse_check \
	gnl \
	key \
	screen \
	screen_col \
	sprite \
	bitmap \
	tools \

FIL = $(addsuffix .c, $(addprefix files/, $(SRC)))

OBJ = $(FIL:.c=.o)

BIN = $(addsuffix .o, $(SRC))

.PHONY: all clean fclean re bonus test sqr bmp err inv norm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) -L $(MLX) $(LXFLAGS) $(OBJ)

clean:
	rm -rf $(OBJ)
	rm -f bitmap.bmp

fclean: clean
	rm -f $(NAME)

re: fclean all
