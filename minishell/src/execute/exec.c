/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocelynnns <yocelynnns@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:08:26 by ysetiawa          #+#    #+#             */
/*   Updated: 2025/02/05 01:03:18 by yocelynnns       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
	int org_fd[2];

	org_fd[0] = dup(STDIN_FILENO);
	org_fd[1] = dup(STDOUT_FILENO);
	if (ast->type == AST_COMMAND)
	{
		cmdchecks(ast, mini, org_fd);
		if (fork_and_execute(ast, env, mini, &status) < 0)
			return ;
	}
	else if (ast->type == AST_PIPELINE)
		execute_pipeline(ast, env, mini);
	dup2(org_fd[0], STDIN_FILENO);
	dup2(org_fd[1], STDOUT_FILENO);
	close(org_fd[0]);
	close(org_fd[1]);
}

void	cmdchecks(t_ast_node *ast, t_minishell *mini, int *org_fd)
{
	if (ast->command->redirect)
		handle_all_redirections(ast, mini);
	if (ast->command->heredoc)
		handle_heredoc(ast);
	if (((ast->command->args[0] == NULL) || (ast->command->args[0][0] == '\0'))
		&& (mini->flag == 1))
	{
		close(org_fd[0]);
		close(org_fd[1]);
		cleanup(mini);
		return ;
	}
}

int	execute_in_child(t_ast_node *ast, char **env, t_minishell *mini)
{
	char	*executable_path;
	int		i;

	if (ast->command->args[0] == NULL)
		exit(EXIT_SUCCESS);
	executable_path = get_executable_path(ast, mini);
	if (executable_path)
	{
		if (execve(executable_path, ast->command->args, env) == -1)
		{
			perror("execve");
			exit(g_sig.exit_value);
			return (-1);
		}
	}
	else
	{
		write(2, "Command not found: ", 19);
		write(2, ast->command->args[0], ft_strlen(ast->command->args[0]));
		write(2, "\n", 1);
		g_sig.exit_value = 127;
		i = g_sig.exit_value;
		cleanup(mini);
		exit(i);
		return (-1);
	}
	return (0);
}

		// if (ast->command->redirect)
		// 	handle_all_redirections(ast, mini);
		// if (ft_strcmp(ast->command->args[0], "cd") == 0)
		// 	ft_cd(ast->command->args, mini->env);
		// else if (ft_strcmp(ast->command->args[0], "export") == 0)
		// {
		// 	if (!ast->command->redirect)
		// 		ft_export(ast->command->args, &mini->env);
		// }
		// else if (ft_strcmp(ast->command->args[0], "unset") == 0)
		// {
		// 	if (!ast->command->redirect)
		// 		ft_unset(ast->command->args, mini);
		// }
		// else if (ft_strcmp(ast->command->args[0], "exit") == 0)
		// 	ft_exit(ast->command->args, mini);

// printf("Command not found: %s\n", ast->command->args[0]);
// expand_variables_in_args(ast->command->args, mini.env);
