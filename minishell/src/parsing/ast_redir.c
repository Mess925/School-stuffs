/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysetiawa <ysetiawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:48:44 by yocelynnns        #+#    #+#             */
/*   Updated: 2025/01/22 13:15:17 by ysetiawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_redirect(int type)
{
	return (type == REDIRECT_IN || type == REDIRECT_OUT || type == APPEND
		|| type == HEREDOC);
}

void	attach_redirect(t_ast_node *cmd, t_ast_node *redirect_node)
{
	t_ast_node	*last;

	if (!cmd->command->redirect)
		cmd->command->redirect = redirect_node;
	else
	{
		last = cmd->command->redirect;
		while (last->redirect && last->redirect->next)
			last = last->redirect->next;
		last->redirect->next = redirect_node;
	}
}

int	handle_redirect(t_ast_node *cmd, t_token **tokens, t_minishell *mini)
{
	t_ast_node	*redirect_node;

	redirect_node = parse_redirect(tokens, mini);
	if (!redirect_node)
	{
		free_ast(cmd);
		return (0);
	}
	attach_redirect(cmd, redirect_node);
	if (redirect_node->redirect->type == HEREDOC)
		cmd->command->heredoc = read_heredoc(redirect_node->redirect->file,
				mini);
	return (1);
}

// int	handle_redirect(t_ast_node *cmd, t_token **tokens, t_minishell *mini)
// {
// 	t_ast_node	*redirect_node;
// 	pid_t		pid;
// 	int			status;

// 	redirect_node = parse_redirect(tokens, mini);
// 	if (!redirect_node)
// 	{
// 		free_ast(cmd);
// 		return (0);
// 	}
// 	attach_redirect(cmd, redirect_node);
// 	if (redirect_node->redirect->type == HEREDOC)
// 	{
// 		pid = fork();
// 		if (pid == 0)
// 		{
// 			cmd->command->heredoc = read_heredoc(redirect_node->redirect->file,
// 					mini);
// 			if (!cmd->command->heredoc)
// 				exit(mini->exit);
// 			exit(0);
// 		}
// 		else if (pid < 0)
// 		{
// 			perror("fork");
// 			free_ast(cmd);
// 			return (0);
// 		}
// 		waitpid(pid, &status, 0);
// 		if (WIFEXITED(status))
// 		{
// 			mini->exit = WEXITSTATUS(status);
// 			if (mini->exit != 0)
// 			{
// 				free_ast(cmd);
// 				return (0);
// 			}
// 		}
// 		else if (WIFSIGNALED(status))
// 		{
// 			mini->exit = mini->exit;
// 			free_ast(cmd);
// 			return (0);
// 		}
// 	}
// 	return (1);
// }
