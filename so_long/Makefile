# Determine OS type
UNAME := $(shell uname)

# Include paths and linker flags based on the OS
ifeq ($(UNAME), Linux)
	INCLUDES = -I/usr/include -Imlx
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else ifeq ($(UNAME), Darwin)
	INCLUDES = -I/usr/X11/include -Imlx
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

# Paths to MiniLibX and libft
MLX_PATH = ./mlx
MLX_LIB = $(MLX_PATH)/libmlx.a
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Compilation flags
CFLAGS = -Werror -Wall -Wextra $(INCLUDES)
SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c main.c controller.c map.c map_check.c map_helper.c is_map_valid.c player.c background.c image_init.c 
OBJS = $(SRCS:.c=.o)
CC = cc
NAME = so_long

# Default rule
all: $(LIBFT) $(NAME)

# Link the game with MiniLibX, libft, and other flags
$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) $(LIBFT)

# Compile the MiniLibX library if not already compiled
$(MLX_LIB):
	make -C $(MLX_PATH) all

# Compile libft if not already compiled
$(LIBFT):
	make -C $(LIBFT_PATH) all

# Clean up object files
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean
	@echo "\033[33m[Cleaned up]\033[0m"

# Clean object files and the executable
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	@echo "\033[33m[Fully cleaned up]\033[0m"

# Recompile everything
re: fclean all

# Compile .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
