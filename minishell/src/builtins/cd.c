/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:44:24 by messs             #+#    #+#             */
/*   Updated: 2025/01/24 14:25:55 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void print_cd_error(const char *path, t_minishell *mini)
{
	if (access(path, 0) != 0)
		ft_putstr_fd("cd: no such file or directory: ", STDERR);
	else if (access(path, 1) != 0)
		ft_putstr_fd("cd: permission denied: ", STDERR);
	else
		ft_putstr_fd("cd: error: ", STDERR);
	ft_putstr_fd((char *)path, STDERR);
	ft_putendl_fd("", STDERR);
	mini->exit = 1;
}

int update_oldpwd(t_env *env_list)
{
	char current_directory[PATH_MAX];
	char *new_value;
	t_env *oldpwd_node;

	if (!getcwd(current_directory, sizeof(current_directory)))
		return (ERROR);
	oldpwd_node = env_list;
	while (oldpwd_node)
	{
		if (ft_strncmp(oldpwd_node->value, "OLDPWD=", 7) == 0)
		{
			free(oldpwd_node->value);
			new_value = malloc(ft_strlen("OLDPWD=") + ft_strlen(current_directory) + 1);
			if (!new_value)
				return (ERROR);
			ft_memcpy(new_value, "OLDPWD=", 7);
			ft_memcpy(new_value + 7, current_directory,
					  ft_strlen(current_directory) + 1);
			oldpwd_node->value = new_value;
			return (SUCCESS);
		}
		oldpwd_node = oldpwd_node->next;
	}
	return (SUCCESS);
}

char *get_special_directory_path(int option, t_env *env_list)
{
	if (option == 0)
		return (get_env_variable(env_list, "HOME=", 5));
	else if (option == 1)
		return (get_env_variable(env_list, "OLDPWD=", 7));
	return (NULL);
}

int navigate_to_special_dir(int option, t_env *env_list, t_minishell *mini)
{
	char *directory_path;
	int result;

	directory_path = get_special_directory_path(option, env_list);
	if (!directory_path)
	{
		if (option == 0)
			ft_putendl_fd("minishell: cd: HOME not set", STDERR);
		else if (option == 1)
			ft_putendl_fd("minishell: cd: OLDPWD not set", STDERR);
		return (ERROR);
	}
	result = chdir(directory_path);
	if (result != 0)
		print_cd_error(directory_path, mini);
	free(directory_path);
	return (result);
}

int ft_cd(char **arguments, t_env *env_list, t_minishell *mini)
{
	if (!arguments[1] || ft_strcmp(arguments[1], "~") == 0 || ft_strcmp(arguments[1], "-") == 0)
		return (handle_special_cd(arguments, env_list, mini));
	if (arguments[1] && ft_strcmp(arguments[1], "") == 0)
		return (SUCCESS);
	return (handle_regular_cd(arguments[1], env_list, mini));
}
