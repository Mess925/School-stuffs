# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>

int ft_popen(const char *file, const char *argv[], char type)
{
    if(!file || !argv || (type != 'r' && type != 'w'))
        return (-1);
    
}