/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysetiawa <ysetiawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:22:00 by yocelynnns        #+#    #+#             */
/*   Updated: 2025/02/13 21:30:25 by ysetiawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	handle_builtin_commands(t_ast_node *ast, t_minishell *mini, t_cmd *m)
{
	if (!ast || ast->type != AST_COMMAND || !ast->command
		|| !*(ast->command->args))
		return (0);
	if (ft_strcmp(ast->command->args[0], "echo") == 0)
		return (ft_echo(ast->command->args, mini), 0);
	else if (ft_strcmp(ast->command->args[0], "cd") == 0)
		return (ft_cd(ast->command->args, mini->env, mini), 0);
	else if (ft_strcmp(ast->command->args[0], "pwd") == 0)
		return (ft_pwd(), 0);
	else if (ft_strcmp(ast->command->args[0], "env") == 0)
		return (ft_env(mini->env), 0);
	else if (ft_strcmp(ast->command->args[0], "export") == 0)
		return (ft_export(ast->command->args, &mini->env, mini), 0);
	else if (ft_strcmp(ast->command->args[0], "unset") == 0)
		return (ft_unset(ast->command->args, mini), 0);
	else if (ft_strcmp(ast->command->args[0], "exit") == 0)
	{
		close(m->org_fd[0]);
		close(m->org_fd[1]);
		return (ft_exit(ast->command->args, mini), 0);
	}
	return (1);
}

int	handle_redirection(t_ast_node *redirect)
{
	int	fd;

	if (redirect->redirect->type == REDIRECT_IN)
		fd = open(redirect->redirect->file, O_RDONLY);
	else if (redirect->redirect->type == REDIRECT_OUT)
		fd = open(redirect->redirect->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redirect->redirect->type == APPEND)
		fd = open(redirect->redirect->file, O_WRONLY | O_CREAT | O_APPEND,
				0644);
	else
		return (0);
	if (fd < 0)
	{
		perror("open");
		return (-1);
	}
	if (redirect->redirect->type == REDIRECT_IN)
		dup2(fd, STDIN_FILENO);
	else
		dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	handle_all_redirections(t_ast_node *ast)
{
	t_ast_node	*redirect;

	redirect = ast->command->redirect;
	while (redirect)
	{
		if (handle_redirection(redirect) < 0)
			return (-1);
		if (!redirect->redirect)
			break;
		redirect = redirect->redirect->next;
	}
	return (0);
}

void	handle_heredoc(t_ast_node *ast)
{
	int	pipefd[2];

	pipe(pipefd);
	write(pipefd[1], ast->command->heredoc, ft_strlen(ast->command->heredoc));
	close(pipefd[1]);
	dup2(pipefd[0], STDIN);
	close(pipefd[0]);
}

t_heredoc	*init_heredoc(const char *delimiter)
{
	t_heredoc	*hd;

	hd = malloc(sizeof(t_heredoc));
	if (!hd)
	{
		perror("malloc");
		return (NULL);
	}
	hd->content = malloc(INITIAL_SIZE);
	if (!hd->content)
	{
		perror("malloc");
		free(hd);
		return (NULL);
	}
	hd->total_length = 0;
	hd->current_size = INITIAL_SIZE;
	hd->delimiter = delimiter;
	hd->delimiter_length = ft_strlen(delimiter);
	return (hd);
}
