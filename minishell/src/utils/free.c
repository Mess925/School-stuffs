/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysetiawa <ysetiawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:41:11 by messs             #+#    #+#             */
/*   Updated: 2025/01/22 20:43:57 by ysetiawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->value);
		free(env);
		env = tmp;
	}
}

void	free_dirs(char **dirs)
{
	int	j;

	j = 0;
	while (dirs[j] != NULL)
	{
		free(dirs[j]);
		j++;
	}
	free(dirs);
}

void	free_tokens(t_token *tokens)
{
	t_token	*temp;

	while (tokens)
	{
		temp = tokens;
		tokens = tokens->next;
		if (temp->value)
            free(temp->value);
		free(temp);
	}
}

void	free_ast(t_ast_node *node)
{
	int	i;

	if (!node)
		return ;
	if (node->type == AST_COMMAND)
	{
		if (node->command)
		{
			if (node->command->args)
			{
				i = 0;
				while (node->command->args[i])
				{
					free(node->command->args[i]);
					i++;
				}
				free(node->command->args);
			}
			free(node->command->heredoc);
			free_ast(node->command->redirect);
			free(node->command);
		}
	}
	if (node->type == AST_PIPELINE)
	{
		if (node->pipeline)
		{
			free_ast(node->pipeline->left);
			free_ast(node->pipeline->right);
			free(node->pipeline);
		}
	}
	if (node->type == AST_REDIRECT)
	{
		if (node->redirect)
		{
			free_ast(node->redirect->next);
			free(node->redirect->file);
			free(node->redirect);
		}
	}
	if (node->type == AST_WORD)
		free(node->word);
	free(node);
}

void	free_node(t_minishell *mini, t_env *env)
{
	if (mini->env == env && env->next == NULL)
	{
		free(mini->env->value);
		mini->env->value = NULL;
		mini->env->next = NULL;
		return ;
	}
	free(env->value);
	free(env);
}
