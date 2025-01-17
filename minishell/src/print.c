/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:21:15 by ysetiawa          #+#    #+#             */
/*   Updated: 2024/12/27 15:54:16 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_tokens(t_token *tokens)
{
	while (tokens)
	{
		printf("Token: %-10s Type: %d\n", tokens->value, tokens->type);
		tokens = tokens->next;
	}
}

void	print_ast(t_ast_node *node, int depth)
{
	int	i;
	int	j;
	int	k;

	if (!node)
		return ;
	i = 0;
	while (i < depth)
	{
		printf("  ");
		i++;
	}
	if (node->type == AST_PIPELINE)
	{
		printf("PIPELINE\n");
		print_ast(node->pipeline->left, depth + 1);
		print_ast(node->pipeline->right, depth + 1);
	}
	else if (node->type == AST_COMMAND)
	{
		printf("COMMAND: [");
		j = 0;
		while (node->command->args[j])
		{
			printf("\"%s\"", node->command->args[j]);
			if (node->command->args[j + 1])
				printf(", ");
			j++;
		}
		printf("]\n");
		if (node->command->redirect)
			print_ast(node->command->redirect, depth + 1);
	}
	else if (node->type == AST_REDIRECT)
	{
		printf("REDIRECT:\n");
		k = 0;
		while (k < depth + 1)
		{
			printf("  ");
			k++;
		}
		if (node->redirect->type == REDIRECT_OUT)
			printf("TYPE: >\n");
		else if (node->redirect->type == APPEND)
			printf("TYPE: >>\n");
		else if (node->redirect->type == REDIRECT_IN)
			printf("TYPE: <\n");
		else if (node->redirect->type == HEREDOC)
			printf("TYPE: <<\n");
		for (i = 0; i <= depth; i++)
			printf("  ");
		printf("FILE: \"%s\"\n", node->redirect->file);
	}
	else if (node->type == AST_WORD)
		printf("WORD: \"%s\"\n", node->word);
	else
		printf("UNKNOWN NODE TYPE\n");
}
