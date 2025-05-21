#ifndef __MICROSHELL_H__
# define __MICROSHELL_H__

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>

#endif

int saved_stdin;

int ft_strlen(char *str)
{
	int length = 0;

	while (str[length])
		length++;
	return (length);
}

int ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

int exec_cd(char **args, int arg_count)
{
	if (arg_count != 2)
		return (ft_error("error: cd: bad arguments\n"));
	if (chdir(args[1]) == -1)
	{
		ft_error("error: cd: cannot change dir to ");
		ft_error(args[1]);
		return (ft_error("\n"));
	}
	return (0);
}

int exec_cmd(char **args, int arg_count, char **envp)
{
	int pid;
	int is_pipe = (args[arg_count] && !strcmp(args[arg_count], "|"));
	int status;
	int pipe_fd[2];

	if (is_pipe && pipe(pipe_fd) == -1)
		return (ft_error("error: fatal\n"));

	pid = fork();
	if (pid == 0) // Child process
	{
		args[arg_count] = NULL; // Terminate arguments at the pipe or semicolon
		if (dup2(saved_stdin, 0) == -1 | close(saved_stdin) == -1)
			return (ft_error("error: fatal\n"));

		if (is_pipe)
		{
			if (dup2(pipe_fd[1], 1) == -1 | close(pipe_fd[0]) == -1 | close(pipe_fd[1]) == -1)
				return (ft_error("error: fatal\n"));
		}

		execve(args[0], args, envp);
		ft_error("error: cannot execute ");
		ft_error(args[0]);
		return (ft_error("\n"));
	}

	// Parent process
	if (!is_pipe)
	{
		if (dup2(0, saved_stdin) == -1)
			return (ft_error("error: fatal\n"));
	}
	else
	{
		if (dup2(pipe_fd[0], saved_stdin) == -1 | close(pipe_fd[1]) == -1 | close(pipe_fd[0]) == -1)
			return (ft_error("error: fatal\n"));
	}

	if (waitpid(pid, &status, 0) == -1)
		return (ft_error("error: fatal\n"));

	return (WIFEXITED(status) ? WEXITSTATUS(status) : 1);
}

int main(int argc, char **argv, char **envp)
{
	int ret = 0;
	int i = 0;

	(void)argc;
	saved_stdin = dup(0); // Save the original stdin

	while (argv[i] && argv[++i])
	{
		argv += i;
		i = 0;

		// Count arguments until a pipe ("|") or semicolon (";")
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;

		if (!strcmp(argv[0], "cd"))
			ret = exec_cd(argv, i);
		else if (i > 0)
			ret = exec_cmd(argv, i, envp);
	}

	// Restore the original stdin
	if (dup2(0, saved_stdin) == -1)
		return (ft_error("error: fatal\n"));
	close(saved_stdin);
	return ret;
}