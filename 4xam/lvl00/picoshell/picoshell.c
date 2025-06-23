#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int picoshell(char **cmds[])
{
	int i;
	int fd[2];
	int prev_fd = -1;
	pid_t pid;
	

    char *cmd1[] = {"ls", "-l", NULL};
	char *cmd2[] = {"grep", "c", NULL};


	for(i = 0; cmds[i]; i++)
	{
		if(cmds[i + 1] && pipe(fd) == -1)
			return (1);
		pid = fork();
		if(pid == -1)
			return (1);
		if(pid == 0)
		{
			if(prev_fd != -1)
			{
				dup2(prev_fd, STDIN_FILENO);
				close(prev_fd);
			}
			if(cmds[i + 1])
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if(prev_fd != -1)
			close(prev_fd);
		if(cmds[i + 1])
		{
			close(fd[1]);
			prev_fd = fd[0];
		}
	}
	while(wait(NULL) > 0)
		;
	return (0);
}

int main(int argc, char **argv)
{
	char *cmd1[] = {"ls", "-l", NULL};
	char *cmd2[] = {"grep", "c", NULL};
	char *cmd3[] = {"wc", "-l", NULL};

	char **commands[] = {cmd1, cmd2, NULL};
	
	if(picoshell(commands) == 1)
	{
		return (1);
	}
	return (0);
}