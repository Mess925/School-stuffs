 # include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>
#include <sys/types.h>

int saved_stdin;

int ft_error(char *str)
{
    write(1, str, strlen(str));
    return 1;
}

int exe_cd(char **av, int i)
{
    if (i != 2)
        return(ft_error("cd: bad arg\n"));
    if(chdir(av[0]) == -1)
	{
		ft_error("error: cd: cannot change dir to ");
		ft_error(av[1]);
		return (ft_error("\n"));
	}
	return (0);
}

int exe_cmd(char **av, int i, char **envp)
{
    int pid;
    int has_pipe = (av[i] && !strcmp(av[i] , "|"));
    int status;
    int pipe_fd[2];

    if(has_pipe && pipe(pipe_fd) == -1)
        return (ft_error("error\n"));

    pid =fork();
    if(pid == 0)
    {
        av[i] = NULL;
        if(dup2(saved_stdin, 0) == -1 | close(saved_stdin) == -1)
            return(ft_error ("error\n"));
        if (has_pipe)
        {
            if(dup2(pipe_fd[1], 1)== -1  | close(pipe_fd[0]) == -1 | close(pipe_fd[1]) == -1)
                return (ft_error("error\n"));
        }

        execve(av[0],av, envp);
		ft_error("error: cannot execute ");
		ft_error(av[0]);
		return (ft_error("\n"));
    }
    if(!has_pipe)
    {
        if(dup2(0, saved_stdin) == -1)
            return(ft_error("error\n"));
    }
    else
    {
        if ( dup2(pipe_fd[0],saved_stdin) == -1 | close(pipe_fd[1]) == -1 | close(pipe_fd[1]) == -1)
            return ( ft_error ("error\n"));
    }
    if(waitpid(pid, &status, 0)== -1)
        return (ft_error("error\n"));
    return ( WIFEXITED(status) ? WEXITSTATUS(status) : 1);
}

int main (int ac, char **av, char **envp)
{
    int ret = 0;
    int i = 0;

    (void) ac;
    saved_stdin = dup(0);
    while(av[i] && av[++i])
    {
        av += 1;
        i = 0;
        while (av[i] && strcmp(av[i] , "|") && strcmp(av[i] , ";"))
            i++;
        if (!strcmp(*av, "cd"))
            ret = exe_cd(av, i);
        else if(i > 0)
            ret = exe_cmd(av, i , envp);
    }
    if(dup2(0,saved_stdin) == -1)
        return(ft_error("error\n"));
    close(saved_stdin);
    return ret;
}