/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 06:51:58 by messs             #+#    #+#             */
/*   Updated: 2025/01/06 18:44:58 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_env(t_env *env)
{
	if (!env)
	{
		ft_putendl_fd("No environment variables found.", 1);
		return (SUCCESS);
	}
	while (env)
	{
		if (ft_strchr(env->value, '='))
			ft_putendl_fd(env->value, STDOUT);
		env = env->next;
	}
	return (SUCCESS);
}
int	key_exists_in_env(const char *key, t_env *env)
{
	if (!key || !env)
		return (0);
	while (env)
	{
		if (ft_strncmp(env->value, key, ft_strlen(key)) == 0
			&& (env->value[ft_strlen(key)] == '='
				|| env->value[ft_strlen(key)] == '\0'))
			return (1);
		env = env->next;
	}
	return (0);
}

int	update_env(char *key, char *new_value, t_env **env, t_minishell *mini)
{
	t_env	*tmp;
	size_t	key_len;

	tmp = *env;
	key_len = ft_strlen(key);
	while (tmp)
	{
		if (ft_strncmp(tmp->value, key, key_len) == 0
			&& (tmp->value[key_len] == '=' || tmp->value[key_len] == '\0'))
		{
			free(tmp->value);
			tmp->value = new_value;
			if (!tmp->value)
				return (print_export_error(-1, key, mini));
			return (SUCCESS);
		}
		tmp = tmp->next;
	}
	return (ERROR);
}

char	*get_env_variable(t_env *env_list, const char *variable, size_t len)
{
	while (env_list)
	{
		if (env_list->value && ft_strncmp(env_list->value, variable, len) == 0)
			return (ft_strdup(env_list->value + len));
		env_list = env_list->next;
	}
	return (NULL);
}

char	*get_env_value(const char *key, t_env *env)
{
	char	*delimiter;
	size_t	key_len;

	if (!key || !env)
		return (NULL);
	while (env)
	{
		delimiter = ft_strchr(env->value, '=');
		if (delimiter)
		{
			key_len = delimiter - env->value;
			if (ft_strlen(key) == key_len && ft_strncmp(env->value, key,
					key_len) == 0)
				return (delimiter + 1);
		}
		else if (ft_strcmp(env->value, key) == 0)
			return (NULL);
		env = env->next;
	}
	return (NULL);
}
