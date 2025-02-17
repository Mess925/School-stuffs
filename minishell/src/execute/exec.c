/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysetiawa <ysetiawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:08:26 by ysetiawa          #+#    #+#             */
/*   Updated: 2025/02/13 21:30:11 by ysetiawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_directory(const char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode))
		return (1);
	return (0);
}

void	execute_command(t_ast_node *ast, t_minishell *mini)
{
	t_cmd	m;

	if (ast->type == AST_COMMAND)
	{
		m.org_fd[0] = dup(STDIN_FILENO);
		m.org_fd[1] = dup(STDOUT_FILENO);
		if (cmdchecks(ast, mini) < 0)
		{
			close(m.org_fd[0]);
			close(m.org_fd[1]);
			return ;
		}
		if (fork_and_execute(ast, mini, &m) < 0)
		{
			close(m.org_fd[0]);
			close(m.org_fd[1]);
			return ;
		}
		dup2(m.org_fd[0], STDIN_FILENO);
		dup2(m.org_fd[1], STDOUT_FILENO);
		close(m.org_fd[0]);
		close(m.org_fd[1]);
	}
	else if (ast->type == AST_PIPELINE)
		execute_pipeline(mini, ast);
}

void	pipe_exec_cmd(t_ast_node *ast, t_minishell *mini)
{
	t_cmd	m;

	m.org_fd[0] = dup(STDIN_FILENO);
	m.org_fd[1] = dup(STDOUT_FILENO);

	cmdchecks(ast, mini);
	if (handle_builtin_commands(ast, mini, &m) == 0)
	{
		fkoff(mini, &m, EXIT_SUCCESS);
	}
	init_signals();
	execute_in_child(ast, mini, &m);
	dup2(m.org_fd[0], STDIN_FILENO);
	dup2(m.org_fd[1], STDOUT_FILENO);
	close(m.org_fd[0]);
	close(m.org_fd[1]);
}

int	cmdchecks(t_ast_node *ast, t_minishell *mini)
{
	if (ast->command->redirect)
	{
		if (handle_all_redirections(ast) < 0)
			return (-1);	
	}
	if (ast->command->heredoc)
	{
		handle_heredoc(ast);
		return (0);
	}
	if (((ast->command->args == NULL) || (ast->command->args[0] == NULL) \
	|| (ast->command->args[0][0] == '\0'))
		&& (mini->flag == 1))
		return (0);
	return (0);
}
void fkoff(t_minishell *mini, t_cmd *m, int returnval)
{
	mini->exit = returnval;
	close(m->org_fd[0]);
	close(m->org_fd[1]);
	cleanup(mini);
	exit(returnval);
}

void	execute_in_child(t_ast_node *ast, t_minishell *mini, t_cmd *m)
{
	char	*executable_path;

	if (ast->command->args[0] == NULL)
		fkoff(mini, m, EXIT_SUCCESS);
	if (is_directory(ast->command->args[0]))
	{
		printf("minishell: %s: Is a directory\n", ast->command->args[0]);
		fkoff(mini, m, 126);
	}
	executable_path = get_executable_path(ast, mini);
	if ((executable_path) && (execve(executable_path, ast->command->args, \
	mini->env2) == -1))
	{
			perror("execve");
			fkoff(mini, m, EXIT_FAILURE);
	}
	else
	{
		write(2, "Command not found: ", 19);
		write(2, ast->command->args[0], ft_strlen(ast->command->args[0]));
		write(2, "\n", 1);
		fkoff(mini, m, 127);
	}
}

// void	expand_variables_in_args(char **args, t_env *env)
// {
// 	int		i;
// 	char	*expanded_arg;

// 	i = 0;
// 	while (args[i])
// 	{
// 		expanded_arg = expand_argument(args[i], env);
// 		if (expanded_arg)
// 		{
// 			free(args[i]);
// 			args[i] = expanded_arg;
// 		}
// 		i++;
// 	}
// }

		// if (ast->command->redirect)
		// 	handle_all_redirections(ast, mini);
		// if (ft_strcmp(ast->command->args[0], "cd") == 0)
		// 	ft_cd(ast->command->args, mini->env);
		// else if (ft_strcmp(ast->command->args[0], "export") == 0)
		// {
		// 	if (!ast->command->redirect)
		// 		ft_export(ast->command->args, &mini->env);
		// }
		// else if (ft_strcmp(ast->command->args[0], "unset") == 0)
		// {
		// 	if (!ast->command->redirect)
		// 		ft_unset(ast->command->args, mini);
		// }
		// else if (ft_strcmp(ast->command->args[0], "exit") == 0)
		// 	ft_exit(ast->command->args, mini);

// printf("Command not found: %s\n", ast->command->args[0]);
// expand_variables_in_args(ast->command->args, mini.env);
