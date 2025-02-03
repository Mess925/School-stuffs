/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:23:36 by hthant            #+#    #+#             */
/*   Updated: 2025/02/03 13:49:12 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

size_t	env_size(char *env)
{
	size_t	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	return (i);
}

int	unset_env_var(t_minishell *mini, char *arg)
{
	t_env	*env;
	t_env	*prev;
	char	*key;
	size_t	key_len;

	if (!arg || !mini->env)
		return (SUCCESS);
	env = mini->env;
	prev = NULL;
	while (env)
	{
		key_len = env_size(env->value);
		key = ft_substr(env->value, 0, key_len);
		if (!key)
			return (ERROR);
		if (ft_strcmp(arg, key) == 0)
		{
			free(key);
			if (prev == NULL)
				mini->env = env->next;
			else
				prev->next = env->next;
			free_node(mini, env);
			return (SUCCESS);
		}
		free(key);
		prev = env;
		env = env->next;
	}
	return (SUCCESS);
}

int	ft_unset(char **args, t_minishell *mini)
{
	int	i;

	if (!args[1])
		return (SUCCESS);
	i = 1;
	while (args[i])
	{
		unset_env_var(mini, args[i]);
		i++;
	}
	return (0);
}
