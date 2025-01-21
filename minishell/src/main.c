/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:51:00 by ysetiawa          #+#    #+#             */
/*   Updated: 2025/01/21 10:41:38 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int main(int ac, char **av, char **env)
{
	char *input;
	t_token *tokens;
	t_ast_node *ast;
	t_minishell *mini;
	mini = malloc(sizeof(t_minishell));
	if (!mini)
		return 1;

	mini->exit = 0;

	(void)ac;
	(void)av;

	// Initialize environment variables
	if (env_init(mini, env) == ERROR)
	{
		fprintf(stderr, "Error: Failed to initialize environment variables\n");
		return (EXIT_FAILURE);
	}
	{
		printf(" __   __  ___   __    _  ___   _______  __   __  _______  ___      ___     \n|  |_|  ||   | |  |  | ||   | |       ||  | |  ||       ||   |    |   |    \n|       ||   | |   |_| ||   | |  _____||  |_|  ||    ___||   |    |   |    \n|       ||   | |       ||   | | |_____ |       ||   |___ |   |    |   |    \n|       ||   | |  _    ||   | |_____  ||       ||    ___||   |___ |   |___ \n| ||_|| ||   | | | |   ||   |  _____| ||   _   ||   |___ |       ||       |\n|_|   |_||___| |_|  |__||___| |_______||__| |__||_______||_______||_______|\n");
	}
	init_signals();
	// print_sorted_env(mini.env);
	while (1)
	{
		signal(SIGINT, sig_int_handler);
		signal(SIGQUIT, sig_quit_handler);
		if (g_sig.sigint)
			continue;

		input = readline("minishell$ ");
		handle_eof(input, mini);

		if (*input)
			add_history(input);

		tokens = lexer(input, mini);
		mini->token = tokens;
		// print_tokens(tokens);
		if (!tokens)
		{
			free(input);
			continue;
		}

		ast = build_ast(tokens, mini);
		mini->ast = ast;
		// print_ast(ast, 0);
		if (!ast)
		{
			free_tokens(tokens);
			free(input);
			continue;
		}
		execute_command(ast, env, mini);

		free_tokens(tokens);
		free_ast(ast);
		free(input);
	}
	// // Free the environment
	free_env(mini->env);
	return (mini->exit);
}
