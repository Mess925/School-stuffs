/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:36:11 by hthant            #+#    #+#             */
/*   Updated: 2024/12/27 15:44:25 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*concatenate_parts(char *expanded_arg, char *var_value,
		char *remaining_arg)
{
	char	*new_expanded_arg;

	new_expanded_arg = malloc(ft_strlen(expanded_arg) + ft_strlen(var_value)
			+ ft_strlen(remaining_arg) + 1);
	if (new_expanded_arg)
	{
		ft_strncpy(new_expanded_arg, expanded_arg, strlen(expanded_arg));
		new_expanded_arg[strlen(expanded_arg)] = '\0';
		ft_strcat(new_expanded_arg, var_value);
		ft_strcat(new_expanded_arg, remaining_arg);
	}
	return (new_expanded_arg);
}

char	*expand_argument(char *arg, t_env *env)
{
	char	*expanded_arg;
	int		j;
	char	*tmp_arg;

	j = 0;
	expanded_arg = NULL;
	tmp_arg = ft_strdup(arg);
	if (!tmp_arg)
		return (NULL);
	while (tmp_arg[j] != '\0')
	{
		if (tmp_arg[j] == '$')
		{
			expanded_arg = process_variable(tmp_arg, &j, env);
			if (expanded_arg)
			{
				free(tmp_arg);
				tmp_arg = expanded_arg;
			}
			else
				break ;
		}
		j++;
	}
	return (tmp_arg);
}

void	init_var(char *arg, int *j, t_var_process *vars)
{
	vars->var_name = NULL;
	vars->new_expanded_arg = NULL;
	vars->prefix = ft_strndup(arg, *j);
	vars->var_value = NULL;
	vars->var_start = *j + 1;
	vars->var_length = 0;
}

char	*process_variable(char *arg, int *j, t_env *env)
{
	t_var_process	vars;
	char			*value_to_concatenate;

	init_var(arg, j, &vars);
	if (!isalnum(arg[vars.var_start]) && arg[vars.var_start] != '_')
	{
		vars.new_expanded_arg = concatenate_parts(vars.prefix, "$", arg
				+ vars.var_start);
		free(vars.prefix);
		return (vars.new_expanded_arg);
	}
	while (arg[vars.var_start + vars.var_length] != '\0'
		&& (isalnum(arg[vars.var_start + vars.var_length]) || arg[vars.var_start
				+ vars.var_length] == '_'))
		vars.var_length++;
	vars.var_name = ft_strndup(arg + vars.var_start, vars.var_length);
	if (vars.var_name)
	{
		vars.var_value = get_env_value(vars.var_name, env);
		if (vars.var_value)
			value_to_concatenate = vars.var_value;
		else
			value_to_concatenate = "";
		vars.new_expanded_arg = concatenate_parts(vars.prefix,
				value_to_concatenate, arg + vars.var_start + vars.var_length);
		free(vars.var_name);
	}
	else
		vars.new_expanded_arg = NULL;
	free(vars.prefix);
	*j += vars.var_length;
	return (vars.new_expanded_arg);
}
