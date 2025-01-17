/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:53:38 by hthant            #+#    #+#             */
/*   Updated: 2025/01/05 17:19:47 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_env	*create_env_node(char *value)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
	{
		ft_putendl_fd("Malloc failed for new env node.", 2);
		return (NULL);
	}
	new_node->value = ft_strdup(value);
	if (!new_node->value)
	{
		ft_putendl_fd("ft_strdup failed for env value.", 2);
		free(new_node->value);
		free_env(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

int	init_env_list(t_minishell *mini, char **env_array)
{
	t_env	*env;
	int		i;
	t_env	*new;

	env = create_env_node(env_array[0]);
	if (!env)
	{
		free_env(env);
		return (1);
	}
	mini->env = env;
	i = 1;
	while (env_array[i])
	{
		new = create_env_node(env_array[i]);
		if (!new)
		{
			free_env(mini->env);
			return (1);
		}
		env->next = new;
		env = new;
		i++;
	}
	return (0);
}

int	env_init(t_minishell *mini, char **env_array)
{
	if (!env_array || !env_array[0])
	{
		ft_putendl_fd("env_array is empty or NULL.", 2);
		return (1);
	}
	if (init_env_list(mini, env_array) != 0)
		return (1);
	ft_putendl_fd("Environment variables successfully initialized.", 2);
	return (0);
}

int	count_env_vars(t_env *env)
{
	int		count;
	t_env	*tmp;

	count = 0;
	tmp = env;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	is_valid_env(char *arg)
{
	int	i;

	if (!arg || !ft_isalpha(arg[0]))
		return (0);
	i = 1;
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
