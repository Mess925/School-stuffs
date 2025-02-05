/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysetiawa <ysetiawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:22:59 by yocelynnns        #+#    #+#             */
/*   Updated: 2025/02/05 17:12:14 by ysetiawa         ###   ########.fr       */
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
	if (command && (command[0] == '/' || command[0] == '.'))
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
	int		signal;

	if (handle_builtin_commands(ast, mini) == 0)
		return g_sig.exit_value;
	if (is_directory(ast->command->args[0]))
	{
		g_sig.exit_value = 126;
		printf("minishell: %s: Is a directory\n", ast->command->args[0]);
		return g_sig.exit_value;
	}
	pid = fork();
	if (pid == 0)
	{
		init_signals();
		if (execute_in_child(ast, env, mini) == -1)
			exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
		return (-1);
	}
	g_sig.pid = pid;
	waitpid(g_sig.pid, status, 0);
	g_sig.pid = 0;
	if (WIFSIGNALED(*status))
	{
		signal = WTERMSIG(*status);
		if (signal == SIGINT)
		{
			g_sig.sigint = 1;
			g_sig.exit_value = 130;
			ft_putstr_fd("\n", STDOUT_FILENO);
			rl_on_new_line();
		}
		else if (signal == SIGQUIT)
		{
			g_sig.exit_value = 131;
			if (WCOREDUMP(*status))
				write(STDERR_FILENO, "Quit (core dumped)\n", 20);
			else
				write(STDERR_FILENO, "Quit\n", 5);
			return (131);
		}
	}
	else if (WIFEXITED(*status))
		g_sig.exit_value = WEXITSTATUS(*status);
	return (g_sig.exit_value);
}
