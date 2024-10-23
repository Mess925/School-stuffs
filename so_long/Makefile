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

# Paths to MiniLibX library
MLX_PATH = ./mlx
MLX_LIB = $(MLX_PATH)/libmlx.a
CONTROLLER_PATH = ./src/controller

# Compilation flags
CFLAGS = -Werror -Wall -Wextra $(INCLUDES)
SRCS = ./src/main.c ${CONTROLLER_PATH}/controller.c
OBJS = $(SRCS:.c=.o)
CC = cc
NAME = so_long

# Default rule
all: $(NAME)

# Link the game with MiniLibX and other flags
$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Compile the MiniLibX library if not already compiled
$(MLX_LIB):
	@$(MAKE) -C $(MLX_PATH)


# Clean up object files
clean:
	rm -f $(OBJS)
	@echo "\033[33m[Cleaned up]\033[0m"

# Clean object files and the executable
fclean: clean
	rm -f $(NAME)
	@echo "\033[33m[Fully cleaned up]\033[0m"

# Recompile everything
re: fclean all

# Compile .o files
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -c $< -o $@

.PHONY: all clean fclean re
