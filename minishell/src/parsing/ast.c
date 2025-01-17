/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:09:35 by ysetiawa          #+#    #+#             */
/*   Updated: 2025/01/17 16:43:14 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_ast_node	*create_ast_node(t_ast_node_type type)
{
	t_ast_node	*new_node;

	new_node = malloc(sizeof(t_ast_node));
	if (!new_node)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	new_node->type = type;
	new_node->word = NULL;
	new_node->pipeline = NULL;
	new_node->command = NULL;
	new_node->redirect = NULL;
	return (new_node);
}

t_ast_node	*parse_pipeline(t_token **tokens, t_minishell *mini, int i)
{
	t_ast_node	*left;
	t_ast_node	*right;
	t_ast_node	*pipeline_node;

	left = parse_command(tokens, mini, i);
	if (!left)
		return (NULL);
	while (*tokens && (*tokens)->type == PIPE)
	{
		*tokens = (*tokens)->next;
		right = parse_command(tokens, mini, i);
		if (!right)
		{
			free_ast(left);
			return (NULL);
		}
		pipeline_node = create_ast_node(AST_PIPELINE);
		pipeline_node->pipeline = malloc(sizeof(t_ast_pipeline));
		pipeline_node->pipeline->left = left;
		pipeline_node->pipeline->right = right;
		left = pipeline_node;
	}
	return (left);
}

void	init_cmd(t_ast_node *cmd, int i)
{
	int j;

	cmd->command = malloc(sizeof(t_ast_command));
	if (!cmd->command)
		return ;
	cmd->command->args = malloc(sizeof(char *) * i);
	if (!cmd->command->args)
	{
		free(cmd->command);
		return ;
	}
	j = 0;
	while (j < i)
	{
		cmd->command->args[j] = NULL;
		j++;
	}
	cmd->command->redirect = NULL;
	cmd->command->heredoc = NULL;
}

t_ast_node	*parse_command(t_token **tokens, t_minishell *mini, int i)
{
	t_ast_node	*cmd;
	int			arg_count;

	cmd = NULL;
	cmd = create_ast_node(AST_COMMAND);
	init_cmd(cmd, i);
	arg_count = 0;
	while (*tokens && is_redirect((*tokens)->type))
	{
		if (!handle_redirect(cmd, tokens, mini))
			return (NULL);
	}
	while (*tokens && (*tokens)->type == WORD)
	{
		cmd->command->args[arg_count++] = ft_strdup((*tokens)->value);
		*tokens = (*tokens)->next;
	}
	cmd->command->args[arg_count] = NULL;
	while (*tokens && is_redirect((*tokens)->type))
	{
		if (!handle_redirect(cmd, tokens, mini))
			return (NULL);
	}
	return (cmd);
}

t_ast_node	*parse_redirect(t_token **tokens, t_minishell *mini)
{
	t_ast_node	*redirect_node;

	redirect_node = create_ast_node(AST_REDIRECT);
	redirect_node->redirect = malloc(sizeof(t_ast_redirect));
	redirect_node->redirect->next = NULL;
	redirect_node->redirect->file = NULL;
	redirect_node->redirect->type = (*tokens)->type;
	*tokens = (*tokens)->next;
	if (*tokens && (*tokens)->type == WORD)
	{
		redirect_node->redirect->file = ft_strdup((*tokens)->value);
		*tokens = (*tokens)->next;
	}
	else
	{
		printf("Error: Syntax error near unexpected token `newline'\n");
		free_ast(redirect_node);
		mini->exit = 2;
		return (NULL);
	}
	return (redirect_node);
}
