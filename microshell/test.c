#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

#define STDERR 2

void fatal_error(void)
{
    write(STDERR, "error: fatal\n", strlen("error: fatal\n"));
    exit(1);
}

void cd(char **args, int count)
{
    if (count != 2)
    {
        write(STDERR, "error: cd: bad arguments\n", strlen("error: cd: bad arguments\n"));
        return;
    }
    if (chdir(args[1]) != 0)
    {
        write(STDERR, "error: cd: cannot change directory to ", strlen("error: cd: cannot change directory to "));
        write(STDERR, args[1], strlen(args[1]));
        write(STDERR, "\n", 1);
    }
}

int exec_cmd(char **args, char **env)
{
    execve(args[0], args, env);
    write(STDERR, "error: cannot execute ", strlen("error: cannot execute "));
    write(STDERR, args[0], strlen(args[0]));
    write(STDERR, "\n", 1);
    exit(1);
}

int main(int argc, char **argv, char **env)
{
    int i = 1;
    int pid = 0;
    int fd[2];
    int tmp_fd = dup(STDIN_FILENO);

    while (i < argc)
    {
        char **cmd = &argv[i];
        int count = 0;
        int has_pipe = 0;

        // Count args until ; or |
        while (i < argc && strcmp(argv[i], ";") != 0 && strcmp(argv[i], "|") != 0)
        {
            count++;
            i++;
        }

        if (count == 0)
        {
            i++;
            continue;
        }

        // Check if next is pipe
        if (i < argc && strcmp(argv[i], "|") == 0)
            has_pipe = 1;

        argv[i] = NULL;
        if (strcmp(cmd[0], "cd") == 0)
        {
            cd(cmd, count);
        }
        else
        {
            if (has_pipe && pipe(fd) == -1)
                fatal_error();
            pid = fork();
            if (pid == -1)
                fatal_error();
            if (pid == 0)
            {
                dup2(tmp_fd, STDIN_FILENO);
                if (has_pipe)
                    dup2(fd[1], STDOUT_FILENO);
                if (has_pipe)
                {
                    close(fd[0]);
                    close(fd[1]);
                }
                exec_cmd(cmd, env);
            }
            else
            {
                waitpid(pid, NULL, 0);
                close(tmp_fd);
                if (has_pipe)
                {
                    close(fd[1]);
                    tmp_fd = fd[0];
                }
                else
                    tmp_fd = dup(STDIN_FILENO);
            }
        }
        i++;
    }
    close(tmp_fd);
    return 0;
}

if I
    do
        int pid = fork();
if (pid == 0)
{
    int x = 0;
}
else
{
    int x = 1;
}