/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysetiawa <ysetiawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:08:26 by ysetiawa          #+#    #+#             */
/*   Updated: 2025/01/22 18:07:55 by ysetiawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	expand_variables_in_args(char **args, t_env *env)
{
	int		i;
	char	*expanded_arg;

	i = 0;
	while (args[i])
	{
		expanded_arg = expand_argument(args[i], env);
		if (expanded_arg)
		{
			free(args[i]);
			args[i] = expanded_arg;
		}
		i++;
	}
}

int	is_directory(const char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode))
		return (1);
	return (0);
}

void	execute_command(t_ast_node *ast, char **env, t_minishell *mini)
{
	int	status;

	if (ast->type == AST_COMMAND)
	{
		// expand_variables_in_args(ast->command->args, mini.env);
		if (ft_strcmp(ast->command->args[0], "exit") == 0)
			ft_exit(ast->command->args, mini);
		else if (ft_strcmp(ast->command->args[0], "cd") == 0)
			ft_cd(ast->command->args, mini->env);
		else if (ft_strcmp(ast->command->args[0], "export") == 0)
		{
			if (!ast->command->redirect)
				ft_export(ast->command->args, &mini->env);
		}
		else if (ft_strcmp(ast->command->args[0], "unset") == 0)
		{
			if (!ast->command->redirect)
				ft_unset(ast->command->args, mini);
		}
		else if (fork_and_execute(ast, env, mini, &status) < 0)
			return ;
	}
	else if (ast->type == AST_PIPELINE)
		execute_pipeline(ast, env, mini);
}

void	cmdchecks(t_ast_node *ast, t_minishell *mini)
{
	// ast->command->args[0] == NULL; 
	if (ast->command->redirect)
		handle_all_redirections(ast, mini);
	if (ast->command->heredoc)
		handle_heredoc(ast);
	if (handle_builtin_commands(ast, mini) == 1)
	{
		free_tokens(mini->token);
		free_ast(ast);
		free_env(mini->env);
		free(mini);
		exit(EXIT_SUCCESS);
	}
	if ((ast->command->args[0] == NULL) || ((ast->command->args[0][0] == '\0') && (mini->flag == 1)))
	{
		free_tokens(mini->token);
		free_ast(ast);
		free_env(mini->env);
		free(mini);
		exit(EXIT_SUCCESS);
	}
	if (is_directory(ast->command->args[0]))
	{
		printf("minishell: %s: Is a directory\n", ast->command->args[0]);
		exit(126);
	}
}

int	execute_in_child(t_ast_node *ast, char **env, t_minishell *mini)
{
	char	*executable_path;
	int		i;

	cmdchecks(ast, mini);
	executable_path = get_executable_path(ast, mini);
	if (executable_path)
	{
		if (execve(executable_path, ast->command->args, env) == -1)
		{
			perror("execve");
			exit(mini->exit);
			return (-1);
		}
	}
	else
	{
		write(2, "Command not found: ", 19);
		write(2, ast->command->args[0], ft_strlen(ast->command->args[0]));
		write(2, "\n", 1);
		mini->exit = 127;
		free_tokens(mini->token);
		free_ast(ast);
		free_env(mini->env);
		i = mini->exit;
		free(mini);
		exit(i);
		return (-1);
	}
	return (0);
}

// printf("Command not found: %s\n", ast->command->args[0]);
