/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:44:08 by hthant            #+#    #+#             */
/*   Updated: 2025/02/04 15:11:07 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int print_export_error(int error, const char *arg, t_minishell *mini)
{
	int i;

	if (error == -1)
		ft_putstr_fd("export: not valid in this context: ", STDERR);
	else if (error == 0 || error == -3)
		ft_putstr_fd("export: not a valid identifier: ", STDERR);
	i = 0;
	while (arg[i] && (arg[i] != '=' || error == -3))
	{
		write(STDERR, &arg[i], 1);
		i++;
	}
	write(STDERR, "\n", 1);
	mini->exit = 1;
	return (ERROR);
}

char *parse_key_value(char *arg, char **key)
{
	size_t key_len;

	if (ft_strchr(arg, '='))
		key_len = ft_strchr(arg, '=') - arg;
	else
		key_len = ft_strlen(arg);
	*key = ft_substr(arg, 0, key_len);
	if (!(*key))
		return (NULL);
	if (ft_strchr(arg, '='))
		return (ft_strdup(arg));
	return (NULL);
}

int add_or_update_env(char *arg, t_env **env, t_minishell *mini)
{
	char *key;
	char *new_value;

	new_value = parse_key_value(arg, &key);
	if (!key)
		return (print_export_error(-1, arg, mini));
	if (!new_value)
	{
		if (key_exists_in_env(key, *env))
		{
			free(key);
			return (SUCCESS);
		}
		if (add_env_node(ft_strdup(key), env, mini) == ERROR)
		{
			free(key);
			return (print_export_error(-1, arg, mini));
		}
		free(key);
		return (SUCCESS);
	}
	if (update_env(key, new_value, env, mini) == SUCCESS)
	{
		free(key);
		return (SUCCESS);
	}
	return (add_env(new_value, env, mini));
}

int add_env(char *new_value, t_env **env, t_minishell *mini)
{
	char *key;
	size_t key_len;
	char *delimiter;

	if (!new_value)
		return (ERROR);
	delimiter = ft_strchr(new_value, '=');
	if (delimiter)
		key_len = delimiter - new_value;
	else
		key_len = ft_strlen(new_value);
	key = ft_substr(new_value, 0, key_len);
	if (!key)
		return (print_export_error(-1, new_value, mini));
	if (key_exists_in_env(key, *env))
	{
		free(key);
		free(new_value);
		return (SUCCESS);
	}
	free(key);
	return (add_env_node(new_value, env , mini));
}

int ft_export(char **args, t_env **env, t_minishell *mini)
{
	int i;
	int error;

	if (!args[1])
	{
		print_sorted_env(*env);
		return (SUCCESS);
	}
	i = 1;
	error = SUCCESS;
	while (args[i])
	{
		if (!is_valid_env(args[i]))
			error = print_export_error(0, args[i], mini);
		else if (add_or_update_env(args[i], env, mini) == ERROR)
		{
			ft_putstr_fd("export: failed to allocate memory for: ", STDERR);
			ft_putendl_fd(args[i], STDERR);
			error = ERROR;
		}
		i++;
	}
	return (error);
}
