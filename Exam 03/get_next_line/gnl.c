#include "gnl.h"

char *ft_strdup(char *str)
{
    char *dest;
    int i = 0;

    while (str[i])
        i++;
    dest = (char*) malloc((sizeof(char) * i+1));
    i = 0;
    while (str[i])
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    char line[70000];
    static int buffer_pos =  0;
    static int buffer_read = 0;
    int i = 0;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while (1)
    {
        if(buffer_pos >= buffer_read)
        {
            buffer_read = read(fd,buffer,BUFFER_SIZE);
            buffer_pos = 0;
            if(buffer_read <= 0)
                break;
        }
        line[i] = buffer[buffer_pos++];
        if(line[i] == '\n')
            break;
        i++;
    }
    i++;
    line[i] = '\0';
    if(i == 0)
        return NULL;
    return (ft_strdup(line));
}

int main()
{
    int fd = open("test.txt",O_RDONLY);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    return 0;
}