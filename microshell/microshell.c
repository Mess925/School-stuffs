#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("test.txt", O_WRONLY);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    printf("HI\n");
}

// int main(int ac, char **av, char **env)
// {
//     void(ac);

//     return (0);
// }