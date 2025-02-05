/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:54:12 by messs             #+#    #+#             */
/*   Updated: 2025/02/05 17:39:49 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <limits.h>

int	check_is_number(char *str)
{
	int	i;

	if (str == NULL || *str == '\0')
		return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (str[i] == '\0');
}

int	ft_exit(char **av, t_minishell *mini)
{
	if (av[1] && check_is_number(av[1]) == 0)
	{
		print_exit_error(av[1]);
		cleanup(mini);
		exit(2);
	}
	else if (av[1] && av[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", STDERR);
		g_sig.exit_value = 1;
		return (1);
	}
	else if (av[1])
		g_sig.exit_value = ft_atol(av[1], mini);
	cleanup(mini);
	if(isatty(STDIN))
		ft_putstr_fd("exit\n",STDERR);
	exit(g_sig.exit_value % 256);
}

int	add_env_node(char *new_value, t_env **env)
{
	t_env	*new_node;
	t_env	*last;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (print_export_error(-1, ft_strdup(new_value)));
	new_node->value = new_value;
	new_node->next = NULL;
	if (!*env)
		*env = new_node;
	else
	{
		last = *env;
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
	return (SUCCESS);
}

int	handle_key_value(char *key, char *new_value, t_env **env)
{
	if (update_env(key, new_value, env) == SUCCESS)
	{
		free(key);
		return (SUCCESS);
	}
	return (add_env(new_value, env));
}

int	add_or_update_env(char *arg, t_env **env)
{
	char	*key;
	char	*new_value;

	new_value = parse_key_value(arg, &key);
	if (!key)
		return (print_export_error(-1, arg));
	if (!new_value)
		return (handle_key_only(key, arg, env));
	return (handle_key_value(key, new_value, env));
}
