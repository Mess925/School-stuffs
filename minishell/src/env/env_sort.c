/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 01:07:06 by messs             #+#    #+#             */
/*   Updated: 2025/01/08 18:38:06 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**create_env_array(int count)
{
	char	**env_array;

	env_array = malloc(sizeof(char *) * (count + 1));
	if (!env_array)
		return (NULL);
	env_array[count] = NULL;
	return (env_array);
}

int	copy_env_values(t_env *env, char **env_array)
{
	t_env	*tmp;
	int		i;
	char	*formatted_value;

	tmp = env;
	i = 0;
	while (tmp)
	{
		formatted_value = format_env_value(tmp->value);
		if (!formatted_value)
		{
			while (i > 0)
				free(env_array[--i]);
			return (1);
		}
		env_array[i++] = formatted_value;
		tmp = tmp->next;
	}
	return (SUCCESS);
}

char	**env_to_array(t_env *env, int count)
{
	char	**env_array;

	if (!env || count <= 0)
		return (NULL);
	env_array = create_env_array(count);
	if (!env_array)
		return (NULL);
	if (copy_env_values(env, env_array) != 0)
	{
		free(env_array);
		return (NULL);
	}
	return (env_array);
}

void	sort_env_array(char **env_array, int count)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strcmp(env_array[i], env_array[j]) > 0)
			{
				temp = env_array[i];
				env_array[i] = env_array[j];
				env_array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	print_sorted_env(t_env *env)
{
	char	**env_array;
	int		count;
	int		i;

	count = count_env_vars(env);
	if (count == 0)
		return ;
	env_array = env_to_array(env, count);
	if (!env_array)
	{
		ft_putstr_fd("Error: Memory allocation failed in print_sorted_env\n",
			STDERR);
		return ;
	}
	sort_env_array(env_array, count);
	i = 0;
	while (i < count)
	{
		ft_putstr_fd("declare -x ", STDOUT);
		ft_putendl_fd(env_array[i], STDOUT);
		free(env_array[i]);
		i++;
	}
	free(env_array);
}
