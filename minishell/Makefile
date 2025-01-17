NAME            = minishell

INC				= inc/
SRC_DIR         = src/

CC              = cc
CFLAGS          = -Wall -Werror -Wextra -g -I$(INC)
LDFLAGS			= -lreadline
RM              = rm -f

LIBFT_PATH      = libft
LIBFT           = $(LIBFT_PATH)/libft.a

PARSING_DIR		= $(SRC_DIR)parsing/ast.c \
				  $(SRC_DIR)parsing/ast_redir.c \
				  $(SRC_DIR)parsing/token.c \
				  $(SRC_DIR)parsing/token_handlequote.c \
				  $(SRC_DIR)parsing/token_handle.c

BUILTINS_DIR	= $(SRC_DIR)builtins/echo.c \
				  $(SRC_DIR)builtins/pwd.c \
				  $(SRC_DIR)builtins/env.c \
				  $(SRC_DIR)builtins/export.c \
				  $(SRC_DIR)builtins/exit.c\
				  $(SRC_DIR)builtins/cd.c \
				  $(SRC_DIR)builtins/unset.c

SIGNALS_DIR		= $(SRC_DIR)signals/signals.c

ENV_DIR			= $(SRC_DIR)env/env_init.c \
				  $(SRC_DIR)env/env_sort.c\

UTILS_DIR		= $(SRC_DIR)utils/free.c \
				  $(SRC_DIR)utils/utils.c \
				  $(SRC_DIR)utils/sec_util.c

EXEC_DIR		= $(SRC_DIR)execute/exec.c \
				  $(SRC_DIR)execute/exec_handle.c \
				  $(SRC_DIR)execute/exec_path.c \
				  $(SRC_DIR)execute/heredoc.c \
				  $(SRC_DIR)execute/exec_helper.c\
				  $(SRC_DIR)execute/exec_utils.c

SRCS            = $(SRC_DIR)main.c $(SRC_DIR)print.c \
				  $(PARSING_DIR) $(BUILTINS_DIR) \
				  $(ENV_DIR) $(UTILS_DIR) $(EXEC_DIR) \
				  $(SIGNALS_DIR)

OBJS            = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
