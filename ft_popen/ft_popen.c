#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int popen_strlen(const char *av)
{
    int i = 0;
    while (av[i])
        i++;
    return (i);
}

void write_error(const char *str)
{
    write(2, str, popen_strlen(str));
    write(2, "\n", 1);
}

int ft_popen(char *file, char *const argv[], char type)
{
    int pipe_fd[2];
    int pid;

    if (type != 'r' && type != 'w')
        return (-1);
    if (pipe(pipe_fd) == -1)
        return (-1);
    pid = fork();
    if (pid == -1)
        return (-1);
    if (pid == 0)
    {
        if (type == 'r')
        {
            close(pipe_fd[0]);
            if (dup2(pipe_fd[1], STDOUT_FILENO == -1))
                exit(1);
            close(pipe_fd[1]);
        }
        else
        {
            close(pipe_fd[1]);
            if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
                exit(1);
            close(pipe_fd[0]);
        }
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        execvp(file, argv);
        write_error("execvp failed");
        exit(127);
    }
    if (type == 'r')
    {
        close(pipe_fd[1]);
        return (pipe_fd[0]);
    }
    else
    {
        close(pipe_fd[0]);
        return (pipe_fd[1]);
    }
}

int main(void)
{
    char *args[] = {"ls", NULL};
    int fd = ft_popen("ls", args, 'w');
    if (fd == -1)
    {
        perror("ft_popen");
        return (1);
    }
    char buffer[256];
    ssize_t bytes;

    while ((bytes = read(fd, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[bytes] = '\0';
        write(1, buffer, bytes);
    }
    printf("the fd is %d\n", fd);

    close(fd);
    return 0;
}