#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int ft_popen(const char *file, char *const argv[], char type)
{
    int pipefd[2];
    pid_t pid;

    if (type != 'r' && type != 'w')
        return -1;

    if (pipe(pipefd) == -1)
        return -1;

    pid = fork();
    if (pid == -1)
        return -1;

    if (pid == 0)
    {
        if (type == 'r')
        {
            close(pipefd[0]); // close read end
            if (dup2(pipefd[1], STDOUT_FILENO) == -1)
                _exit(1);
        }
        else // type == 'w'
        {
            close(pipefd[1]); // close write end
            if (dup2(pipefd[0], STDIN_FILENO) == -1)
                _exit(1);
        }

        // Close both ends of the pipe after dup
        close(pipefd[0]);
        close(pipefd[1]);

        execvp(file, argv);
        perror("execvp");
        _exit(127);
    }

    // Parent process
    if (type == 'r')
    {
        close(pipefd[1]); // close write end
        return pipefd[0]; // return read end to parent
    }
    else
    {
        close(pipefd[0]); // close read end
        return pipefd[1]; // return write end to parent
    }
}


int main(void)
{
    int fd;
    char *args[] = {"cat","test.txt", NULL};

    fd = ft_popen("cat", args, 'w');
    if (fd == -1)
    {
        perror("ft_popen");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // get_next_line includes '\n'
        free(line);
    }

    close(fd);
    return 0;
}
