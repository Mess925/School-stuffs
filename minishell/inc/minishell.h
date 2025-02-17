/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:51:40 by hthant            #+#    #+#             */
/*   Updated: 2025/02/15 21:50:50 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "../libft/libft.h"
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
// #include <linux/limits.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <termios.h>

#define SUCCESS 0
#define ERROR 1

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define BUFF_SIZE 4096
#define INITIAL_SIZE 4096

typedef enum e_signal_mode
{
	INTERACTIVE,
	HEREDOC_MODE,
	CHILD_PROCESS_MODE,
} t_signal_mode;

typedef enum
{
	WORD,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	HEREDOC,
	APPEND
} t_token_type;

typedef struct s_minishell t_minishell;

typedef struct s_process
{
	char *str;
	int i;
	int in_quote;
	char *result;
	t_minishell *mini;
} t_process;

typedef struct s_token
{
	t_token_type type;
	char *value;
	struct s_token *next;
} t_token;

typedef struct s_lexer_state
{
	int i;
	int start;
	char quote;
	int last_token_was_pipe;
	t_token *token_list;
} t_lexer_state;

typedef enum
{
	AST_PIPELINE,
	AST_COMMAND,
	AST_REDIRECT,
	AST_WORD
} t_ast_node_type;

typedef struct s_ast_node
{
	t_ast_node_type type;
	struct s_ast_pipeline *pipeline;
	struct s_ast_command *command;
	struct s_ast_redirect *redirect;
	char *word;

} t_ast_node;

typedef struct s_ast_command
{
	char **args;
	t_ast_node *redirect;
	char *heredoc;
} t_ast_command;

typedef struct s_ast_pipeline
{
	t_ast_node *left;
	t_ast_node *right;
} t_ast_pipeline;

typedef struct s_ast_redirect
{
	t_ast_node *next;
	char *file;
	int type;
} t_ast_redirect;

typedef struct s_env
{
	char *value;
	struct s_env *next;
} t_env;

typedef struct s_cmd
{
	int status;
	int org_fd[2];
} t_cmd;

typedef struct s_minishell
{
	t_env *env;
	t_token *token;
	t_ast_node *ast;
	t_process *proc;
	int flag;
	int here;
	int exit;
	char **env2;
} t_minishell;

typedef struct s_heredoc
{
	char *content;
	size_t total_length;
	size_t current_size;
	const char *delimiter;
	size_t delimiter_length;
} t_heredoc;

typedef struct s_signal
{
	int sigint;
	// int						sigquit;
	// pid_t					pid;
	// int						exit_value;
} t_signal;

typedef struct s_var_process
{
	char *var_name;
	char *new_expanded_arg;
	char *prefix;
	char *var_value;
	int var_start;
	int var_length;
} t_var_process;

extern t_signal g_sig;

char *ft_strcjoin(char *str, char c);
void stop_signals(void);
int cmdchecks(t_ast_node *ast, t_minishell *mini);
t_token *create_token(t_token_type type, const char *value);
void add_token(t_token **head, t_token *new_token);
t_token *lexer(const char *input, t_minishell *mini);
void free_tokens(t_token *tokens);
void print_tokens(t_token *tokens);
void cleanup(t_minishell *mini);
void handle_quotes(const char *input,
				   t_lexer_state *state);
char *first_processing(char *str, t_minishell *mini);
t_ast_node *create_ast_node(t_ast_node_type type);
t_ast_node *parse_command(t_token **tokens, t_minishell *mini,
						  int i);
t_ast_node *parse_pipeline(t_token *tokens, t_minishell *mini,
						   int i);
t_ast_node *parse_redirect(t_token **tokens,
						   t_minishell *mini);
t_ast_node *build_ast(t_token *tokens, t_minishell *mini);
void free_ast(t_ast_node *node);
void print_ast(t_ast_node *node, int depth);

int is_redirect(int type);
void attach_redirect(t_ast_node *cmd,
					 t_ast_node *redirect_node);
int handle_redirect(t_ast_node *cmd, t_token **tokens,
					t_minishell *mini);

void execute_command(t_ast_node *ast, t_minishell *mini);
char *find_executable(char *cmd, t_minishell *mini);
char *concat_path(char *dir, char *cmd);
char *read_heredoc(const char *delim, t_minishell *mini);

int handle_builtin_commands(t_ast_node *ast, t_minishell *mini, t_cmd *m);
int handle_redirection(t_ast_node *ast);
void handle_heredoc(t_ast_node *ast);
t_heredoc *init_heredoc(const char *delimiter);
char *check_directory(char *dir, char *cmd);
char *get_executable_path(t_ast_node *ast,
						  t_minishell *mini);
int fork_and_execute(t_ast_node *ast, t_minishell *mini, t_cmd *m);
void execute_in_child(t_ast_node *ast, t_minishell *mini, t_cmd *m);
int execute_left_command(int pipefd[2],
						 t_ast_node *ast, t_minishell *mini);
int execute_right_command(int pipefd[2], t_ast_node *ast, t_minishell *mini);
int execute_pipeline(t_minishell *mini, t_ast_node *ast);
void fkoff(t_minishell *mini, t_cmd *m, int returnval);
void pipe_exec_cmd(t_ast_node *ast, t_minishell *mini);
int pipe_execute(t_ast_node *ast, char **env, t_minishell *mini, t_cmd *m);
char *resize_buffer(char *content, size_t total_length,
					size_t *current_size);
ssize_t read_line(char *content, size_t total_length,
				  size_t current_size);
int is_delimiter(const char *content,
				 const char *delimiter, size_t total_length,
				 size_t delimiter_length);
int read_until_delimiter(t_heredoc *hd,
						 t_minishell *mini);
void free_dirs(char **dirs);
int handle_all_redirections(t_ast_node *ast);

int ft_strcmp(const char *s1, const char *s2);
int number_of_args(char **args);
int ft_echo(char **args, t_minishell *mini);
char *remove_quotes(const char *str);
int is_valid_n_flag(const char *arg);

int ft_env(t_env *env);

int init_env_list(t_minishell *mini, char **env_array);
t_env *create_env_node(char *value);
int env_init(t_minishell *mini, char **env);
void print_sorted_env(t_env *env);
void sort_env_array(char **env_array, int count);
char **create_env_array(int count);
int copy_env_values(t_env *env, char **env_array);
char **env_to_array(t_env *env, int count);
int count_env_vars(t_env *env);

int ft_pwd(void);

void free_env(t_env *env);
void free_node(t_minishell *mini, t_env *env);

int check_is_number(char *str);
int ft_exit(char **av, t_minishell *mini);

void print_cd_error(const char *path, t_minishell *mini);
char *get_env_variable(t_env *env_list,
					   const char *variable, size_t len);
int update_oldpwd(t_env *env_list);
char *get_special_directory_path(int option,
								 t_env *env_list);
int navigate_to_special_dir(int option,
							t_env *env_list, t_minishell *mini);
int handle_tilde(char **path, t_env *env_list);
int handle_special_cd(char **arguments,
					  t_env *env_list, t_minishell *mini);
int handle_regular_cd(char *path, t_env *env_list, t_minishell *mini);
int ft_cd(char **arguments, t_env *env_list, t_minishell *mini);

int print_export_error(int error, const char *arg, t_minishell *mini);
int is_valid_env(char *arg);
char *parse_key_value(char *arg, char **key);
int update_env(char *key, char *new_value, t_env **env, t_minishell *mini);
int add_env(char *new_value, t_env **env, t_minishell *mini);
int add_or_update_env(char *arg, t_env **env, t_minishell *mini);
int ft_export(char **args, t_env **env, t_minishell *mini);
int key_exists_in_env(const char *key, t_env *env);
int add_env_node(char *new_value, t_env **env, t_minishell *mini);

size_t env_size(char *env);
int unset_env_var(t_minishell *mini, char *arg);
int ft_unset(char **args, t_minishell *mini);

char *ft_strcpy(char *s1, char *s2);
char *ft_strcat(char *dest, char *src);
char *ft_strndup(const char *s, size_t n);
void init_signals(void);
void handle_eof(char *line, t_minishell *mini);
char *expand_argument(char *arg, t_env *env);
char *process_variable(char *arg, int *j, t_env *env);
char *concatenate_parts(char *expanded_arg,
						char *var_value, char *remaining_arg);
char *get_env_value(const char *key, t_env *env);
char *ft_strncpy(char *dest, char *src, unsigned int n);
long ft_atol(char *str, t_minishell *mini);
void print_exit_error(char *av);
char *ft_strjoin_three(const char *s1, const char *s2,
					   const char *s3, const char *s4);
char *format_env_value(const char *env_value);
int count_cmds(t_token *token);
void ignore_sigquit(int signo);
void set_signals_heredoc(void);
void signal_print_newline(int signal);
void set_signals_interactive(void);
void signal_reset_prompt(int signo);

#endif
