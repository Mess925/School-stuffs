/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysetiawa <ysetiawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:51:00 by ysetiawa          #+#    #+#             */
/*   Updated: 2025/02/13 18:28:25 by ysetiawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void free_minishell(t_minishell *mini, char *input)
{
	free_tokens(mini->token);
	free_ast(mini->ast);
	free(input);
}

void prompt(char *input, t_minishell *mini)
{
	handle_eof(input, mini);
	if (*input)
		add_history(input);
}

void free_tokent(t_token *tokens, char *input)
{
	free_tokens(tokens);
	free(input);
}

// void init_loop(char *input, t_minishell *mini)
// {
// 	init_signals();
// 	input = readline("minishell$ ");
// 	if(g_sig.sigint == 1)
// 		mini->exit = 130;
// 	stop_signals();
// 	prompt(input, mini);
// }

// void exec_free(t_minishell *mini, char **env, char *input)
// {
// 	mini->exit = 0;
// 	execute_command(mini->ast, env, mini);
// 	free_minishell(mini, input);
// }

void run_shell_loop(t_minishell *mini)
{
	char *input; 
	t_token *tokens;
	t_ast_node *ast;

	while (1)
	{
		// init_loop(input, mini);
		init_signals();
		input = readline("minishell$ ");
		if(g_sig.sigint == 1)
			mini->exit = 130;
		stop_signals();
		prompt(input, mini);
		tokens = lexer(input, mini);
		// print_tokens(tokens);
		mini->token = tokens;
		if (!tokens)
		{
			free_tokens(tokens);
			free(input);
			continue;
		}
		ast = build_ast(tokens, mini);
		// print_ast(ast, 0);
		mini->ast = ast;
		if (!ast)
		{
			free_ast(ast);
			free_tokent(tokens, input);
			continue;
		}
		mini->exit = 0;
		execute_command(mini->ast, mini);
		free_minishell(mini, input);
		// exec_free(mini, env, input);
	}
}

void print_welcome_message(void)
{
	printf(" __   __  ___   __    _  ___   _______  __   __  _______  ___ ");
	printf("     ___     \n");
	printf("|  |_|  ||   | |  |  | ||   | |       ||  | |  ||       ||   |");
	printf("    |   |    \n");
	printf("|       ||   | |   |_| ||   | |  _____||  |_|  ||    ___||   |");
	printf("    |   |    \n");
	printf("|       ||   | |       ||   | | |_____ |       ||   |___ |   |");
	printf("    |   |    \n");
	printf("|       ||   | |  _    ||   | |_____  ||       ||    ___||   |");
	printf("___ |   |___ \n");
	printf("| ||_|| ||   | | | |   ||   |  _____| ||   _   ||   |___ |    ");
	printf("   ||       |\n");
	printf("|_|   |_||___| |_|  |__||___| |_______||__| |__||_______||____");
	printf("___||_______|\n");
}

t_minishell *init_minishell(char **env)
{
	t_minishell *mini;

	mini = malloc(sizeof(t_minishell));
	if (!mini)
		return (NULL);
	mini->exit = 0;
	mini->here = 0;
	if (env_init(mini, env) == ERROR)
	{
		ft_putstr_fd("Error: Failed to initialize environment variables\n",STDERR);
		free(mini);
		return (NULL);
	}
	return (mini);
}

int main(int ac, char **av, char **env)
{
	t_minishell *mini;

	(void)ac;
	(void)av;
	mini = init_minishell(env);
	if (!mini)
		return (EXIT_FAILURE);
	print_welcome_message();
	run_shell_loop(mini);
	free_env(mini->env);
	free_env_array(mini->env2);
	free(mini);
	init_signals();

	return (mini->exit);
}

// int main(int ac, char **av, char **env)
// {
// 	char *input;
// 	t_token *tokens;
// 	t_ast_node *ast;
// 	t_minishell *mini;
// 	mini = malloc(sizeof(t_minishell));
// 	if (!mini)
// 		return 1;

// 	mini->exit = 0;

// 	(void)ac;
// 	(void)av;

// 	// Initialize environment variables
// 	if (env_init(mini, env) == ERROR)
// 	{
// 		fprintf(stderr, "Error: Failed to initialize environment variables\n");
// 		return (EXIT_FAILURE);
// 	}
// 	{
// 		printf(" __   __  ___   __    _  ___   _______  __   __  _______  ___      ___     \n|  |_|  ||   | |  |  | ||   | |       ||  | |  ||       ||   |    |   |    \n|       ||   | |   |_| ||   | |  _____||  |_|  ||    ___||   |    |   |    \n|       ||   | |       ||   | | |_____ |       ||   |___ |   |    |   |    \n|       ||   | |  _    ||   | |_____  ||       ||    ___||   |___ |   |___ \n| ||_|| ||   | | | |   ||   |  _____| ||   _   ||   |___ |       ||       |\n|_|   |_||___| |_|  |__||___| |_______||__| |__||_______||_______||_______|\n");
// 	}
// 	init_signals();
// 	// print_sorted_env(mini.env);
// 	while (1)
// 	{
// 		// signal(SIGINT, sig_int_handler);
// 		// signal(SIGQUIT, sig_quit_handler);

// 		input = readline("minishell$ ");
// 		handle_eof(input, mini);

// 		if (*input)
// 			add_history(input);

// 		tokens = lexer(input, mini);
// 		mini->token = tokens;
// 		// print_tokens(tokens);
// 		if (!tokens)
// 		{
// 			free(input);
// 			continue;
// 		}

// 		ast = build_ast(tokens, mini);
// 		mini->ast = ast;
// 		// print_ast(ast, 0);
// 		if (!ast)
// 		{
// 			free_tokens(tokens);
// 			free(input);
// 			continue;
// 		}
// 		execute_command(ast, env, mini);
// 		free_tokens(tokens);
// 		free_ast(ast);
// 		free(input);
// 	}
// 	// // Free the environment
// 	free_env(mini->env);
// 	return (mini->exit);
// }
