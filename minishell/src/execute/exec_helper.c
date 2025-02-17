/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysetiawa <ysetiawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:35:01 by hthant            #+#    #+#             */
/*   Updated: 2025/02/13 21:30:19 by ysetiawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	execute_left_command(int pipefd[2], t_ast_node *ast, t_minishell *mini)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		pipe_exec_cmd(ast, mini);
	}
	else if (pid1 < 0)
	{
		perror("fork");
		return (-1);
	}
	return (pid1);
}

int	execute_right_command(int pipefd[2], t_ast_node *ast, t_minishell *mini)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		execute_command(ast, mini);
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

int	execute_pipeline(t_minishell *mini, t_ast_node *ast)
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
	pid1 = execute_left_command(pipefd, ast->pipeline->left, mini);
	pid2 = execute_right_command(pipefd, ast->pipeline->right, mini);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		mini->exit = WEXITSTATUS(status);
	return (0);
}

// int	execute_pipeline(t_minishell *mini, t_cmd *m, t_ast_node *ast)
// {
// 	int		pipefd[2];
// 	pid_t	pid1;
// 	// pid_t	pid2;
// 	int		status;

// 	if (pipe(pipefd) == -1)
// 	{
// 		perror("pipe");
// 		return (-1);
// 	}
// 	pid1 = execute_left_command(m, pipefd, ast->pipeline->left, mini);
// 	execute_command(ast->pipeline->right, mini);
// 	// pid2 = execute_right_command(m, pipefd, ast->pipeline->right, mini);
// 	if (pid1 > 0)
// 	{
// 		close(pipefd[0]);
// 		close(pipefd[1]);
// 		waitpid(pid1, &status, 0);
// 		if (WIFEXITED(status))
// 			mini->exit = WEXITSTATUS(status);
// 	}
// 	// if (pid2 > 0)
// 	// {
// 	// 	close(pipefd[0]);
// 	// 	close(pipefd[1]);
// 	// 	waitpid(pid2, &status, 0);
// 	// 	if (WIFEXITED(status))
// 	// 		mini->exit = WEXITSTATUS(status);
// 	// }
// 	return (0);
// }
