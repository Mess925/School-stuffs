/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysetiawa <ysetiawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:53:38 by hthant            #+#    #+#             */
/*   Updated: 2025/02/13 14:07:39 by ysetiawa         ###   ########.fr       */
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
			t_env *tmp;

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
			while (mini->env)
			{
				tmp = mini->env;
				mini->env = mini->env->next;
				free_env(tmp);
			}
			return (1);
		}
		env->next = new;
		env = new;
		i++;
	}
	return (0);
}

char **env_list_to_array(t_env *env_list)
{
    t_env *current = env_list;
    int count = 0;
    
    while (current)
    {
        count++;
        current = current->next;
    }
    char **env_array = malloc((count + 1) * sizeof(char *));
    if (!env_array)
        return NULL;
    current = env_list;
    for (int i = 0; i < count; i++)
    {
        env_array[i] = strdup(current->value);
        if (!env_array[i])
        {
            for (int j = 0; j < i; j++)
                free(env_array[j]);
            free(env_array);
            return NULL;
        }
        current = current->next;
    }
    env_array[count] = NULL;
    return env_array;
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
		
	mini->env2 = env_list_to_array(mini->env);
    if (!mini->env2)
    {
        ft_putstr_fd("Error: Failed to convert environment variables to array\n", STDERR);
        return (1);
    }
	// ft_putendl_fd("Environment variables successfully initialized.", 2);
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
