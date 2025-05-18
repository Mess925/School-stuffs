# include <stdio.h>
# include <unistd.h>
# include <string.h>

void exec_cd(char **av, int i)
{
    if (i != 2)
        printf("error\n");
    if (chdir(av[1]) == 0)
        printf("it changed\n");
    else
        printf("errorb\n");
}

void exec_cmd(char **av, int i, char **envp)
{
    return;
}

int main(int ac, char **av, char **envp)
{
    int i = 0;
    (void)ac;
    (void)envp;
    while (av[i] && av [++i])
    {
        av = av + 1;
        i = 0;
        while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
            i++;
        if (strcmp(*av , "cd") == 0)
            exec_cd(av,i);
        else
            exec_cmd(av,i, envp);
    }
    return (0);
}