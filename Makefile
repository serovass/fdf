NAME = fdf

LIST =	main_fdf.c\
		clear.c\
		./read_mapfile.c\
		./gnl/get_next_line.c\
		./gnl/get_next_line_utils.c\
		draw.c\
		draw_straight.c\
		projection.c\
		key_control.c\
		mouse_control.c\

OBJ = ${LIST:.c=.o}

LIBFT_DIR	= ./libft
LIBFT		= ./libft/libft.a
MLX_DIR		= ./minilibx_macos
MLX			= ./minilibx_macos/libmlx.a

FLAGS = -Wall -Wextra -Werror -include fdf.h -O3

all: $(NAME)

bonus: $(NAME)

%.o: %.c
			gcc $(FLAGS) -c $< -o $@

$(LIBFT):
		$(MAKE) -C libft

$(MLX):
		$(MAKE) -C minilibx_macos

$(NAME):	$(OBJ) $(LIBFT) $(MLX)
				gcc $(FLAGS) $(OBJ) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit -o $(NAME)

clean: 
		make -C $(LIBFT_DIR) clean
		rm -f $(OBJ)

fclean: clean
		@make -C $(LIBFT_DIR) fclean
		@make -C $(MLX_DIR) clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re bonus
