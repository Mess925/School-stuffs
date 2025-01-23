/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysetiawa <ysetiawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:22:59 by yocelynnns        #+#    #+#             */
/*   Updated: 2025/01/22 15:37:34 by ysetiawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*concat_path(char *dir, char *cmd)
{
	size_t	dir_len;
	size_t	cmd_len;
	size_t	total_len;
	char	*full_path;

	dir_len = ft_strlen(dir);
	cmd_len = ft_strlen(cmd);
	total_len = dir_len + cmd_len + 2;
	full_path = malloc(total_len);
	if (!full_path)
		return (NULL);
	ft_strcpy(full_path, dir);
	ft_strcat(full_path, "/");
	ft_strcat(full_path, cmd);
	return (full_path);
}

char	*check_directory(char *dir, char *cmd)
{
	char	*full_path;

	full_path = concat_path(dir, cmd);
	if (!full_path)
		return (NULL);
	if (access(full_path, X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

char	*find_executable(char *cmd, t_minishell *mini)
{
	char	*path_env;
	char	**dirs;
	char	*full_path;
	int		i;

	path_env = get_env_value("PATH", mini->env);
	if (!path_env)
		return (NULL);
	dirs = ft_split(path_env, ':');
	if (!dirs)
		return (NULL);
	full_path = NULL;
	i = 0;
	while (dirs[i] != NULL)
	{
		full_path = check_directory(dirs[i], cmd);
		if (full_path)
		{
			free_dirs(dirs);
			return (full_path);
		}
		i++;
	}
	free_dirs(dirs);
	return (NULL);
}

char	*get_executable_path(t_ast_node *ast, t_minishell *mini)
{
	char	*command;
	char	*executable_path;

	command = ast->command->args[0];
	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, X_OK) == 0)
			return (command);
	}
	else
	{
		executable_path = find_executable(command, mini);
		if (executable_path)
			return (executable_path);
	}
	return (NULL);
}

int	fork_and_execute(t_ast_node *ast, char **env, t_minishell *mini,
		int *status)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execute_in_child(ast, env, mini) == -1)
			exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
		return (-1);
	}
	g_sig.pid = pid;
	waitpid(pid, status, 0);
	g_sig.pid = 0;
	if (WIFEXITED(*status))
	{
		mini->exit = WEXITSTATUS(*status);
	}
	else
		mini->exit = g_sig.exit_value;
	return (mini->exit);
}
