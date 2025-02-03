/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:35:01 by hthant            #+#    #+#             */
/*   Updated: 2025/01/24 17:05:37 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	execute_left_command(t_ast_node *ast, int pipefd[2], char **env,
		t_minishell *mini)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execute_command(ast->pipeline->left, env, mini);
		cleanup(mini);
		exit(0);
	}
	else if (pid1 < 0)
	{
		perror("fork");
		return (-1);
	}
	return (pid1);
}

int	execute_right_command(t_ast_node *ast, int pipefd[2], char **env,
		t_minishell *mini)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		close(pipefd[0]);
		execute_command(ast->pipeline->right, env, mini);
		cleanup(mini);
		exit(0);
	}
	else if (pid2 < 0)
	{
		perror("fork");
		return (-1);
	}
	return (pid2);
}

int	execute_pipeline(t_ast_node *ast, char **env, t_minishell *mini)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	pid1 = execute_left_command(ast, pipefd, env, mini);
	pid2 = execute_right_command(ast, pipefd, env, mini);
	if (pid1 > 0)
	{
		waitpid(pid1, &status, 0);
		if (WIFEXITED(status))
			g_sig.exit_value = WEXITSTATUS(status);
		close(pipefd[0]);
		close(pipefd[1]);
	}
	if (pid2 > 0)
	{
		waitpid(pid2, &status, 0);
		if (WIFEXITED(status))
			g_sig.exit_value = WEXITSTATUS(status);
		close(pipefd[0]);
		close(pipefd[1]);
	}
	return (0);
}
