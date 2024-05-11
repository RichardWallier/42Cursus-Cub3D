# Variables declarations

EXE		=	cub3d

SRCS		=	$(addprefix mandatory/src/, main.c \
				$(addprefix hooks/, hook.c key_pressed.c key_released.c) \
				$(addprefix init/, data_init.c elements_init.c image_init.c map_init.c player_init.c) \
				$(addprefix cast/,  raycast.c) \
				$(addprefix render/, draw_ceil_wall_floor.c put_pixel.c set_draw_info.c) \
				$(addprefix utils/, check_extension.c free_matrix.c free_scene.c is_map_line.c is_wall_at.c read_file.c throw_error.c) \
				$(addprefix validations/, validate_colors.c validate_content.c validate_grid.c) \
				)

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

LIBFT_DIR	=	./libft

LIBFT		=	$(LIBFT_DIR)/libft.a

LIBFT_FLAGS	=	-L$(LIBFT_DIR) -lft

# Change MLX to match OS

ifeq ($(shell uname), Linux)
	MLX_DIR		=	./mlx_linux
	MLX_FLAGS	=	-L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
else
	MLX_DIR		=	./mlx
	MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

MLX			=	$(MLX_DIR)/libmlx.a

INCLUDE		=	-I./mandatory/include -I$(LIBFT_DIR) -I$(MLX_DIR)

# Compile Rules

%.o: %.c ./mandatory/include/cub3d.h
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(EXE)

$(MLX):
	@make -s -C $(MLX_DIR)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(EXE): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $@
	@echo "\033[32m 💯 | cub3d mandatory created."

clean:
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MLX_DIR) clean
	@echo "\033[33m 🧹  | cub3d cleaned."

fclean:
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(MLX_DIR) clean
	@echo "\033[33m 🌪️  | cub3d all cleaned."

re: fclean all

.PHONY:	all clean fclean re
