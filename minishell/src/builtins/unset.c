/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:23:36 by hthant            #+#    #+#             */
/*   Updated: 2024/12/18 15:39:11 by hthant           ###   ########.fr       */
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
	t_env	*tmp;

	env = mini->env;
	if (!arg)
		return (SUCCESS);
	if (ft_strncmp(arg, env->value, env_size(env->value)) == 0)
	{
		if (env->next)
			mini->env = env->next;
		free_node(mini, env);
		return (SUCCESS);
	}
	while (env && env->next)
	{
		if (ft_strncmp(arg, env->next->value, env_size(env->next->value)) == 0)
		{
			tmp = env->next->next;
			free_node(mini, env->next);
			env->next = tmp;
			return (SUCCESS);
		}
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
		unset_env_var(mini, args[i]);
		i++;
	}
	return (0);
}
