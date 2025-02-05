/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:23:36 by hthant            #+#    #+#             */
/*   Updated: 2025/02/05 16:17:12 by hthant           ###   ########.fr       */
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

t_env	*find_env_var(t_env *env, char *arg, t_env **prev)
{
	char	*key;
	size_t	key_len;

	*prev = NULL;
	while (env)
	{
		key_len = env_size(env->value);
		key = ft_substr(env->value, 0, key_len);
		if (!key)
			return (NULL);
		if (ft_strcmp(arg, key) == 0)
		{
			free(key);
			return (env);
		}
		free(key);
		*prev = env;
		env = env->next;
	}
	return (NULL);
}

int	remove_env_var(t_minishell *mini, t_env *target, t_env *prev)
{
	if (!target)
		return (SUCCESS);
	if (prev == NULL)
		mini->env = target->next;
	else
		prev->next = target->next;
	free_node(mini, target);
	return (SUCCESS);
}

int	unset_env_var(t_minishell *mini, char *arg)
{
	t_env	*target;
	t_env	*prev;

	if (!arg || !mini->env)
		return (SUCCESS);
	target = find_env_var(mini->env, arg, &prev);
	return (remove_env_var(mini, target, prev));
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
