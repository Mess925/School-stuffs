#include "get_next_line.h"

char *ft_strdup(char *line)
{
    char *dest;
    int i = 0;
    while (line[i])
        i++;
    dest = (char *)malloc(sizeof(char)*i+1);
    if(!dest)
        return NULL;
    i = 0;
    while (line[i])
    {
        dest[i] = line[i];
        i++;
    }
    dest[i] ='\0';
    return dest;
}


char	  *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int buffer_pos = 0;
    static int buffer_read = 0;
    int i = 0;
    int j = 0;
    int line_length = BUFFER_SIZE;
    char *line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    char *new_line;

    if(!line)
        return NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while (1)
    {
        if(buffer_pos >= buffer_read)
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if(buffer_read <= 0)
            {
                free(line);
                return NULL;
            }
        }
        line[i] = buffer[buffer_pos++];
        if (line[i] == '\n')
        {
            i++;
            break;
        }
        i++;
        if(i >= line_length - 1 )
        {
            line_length += BUFFER_SIZE;
            new_line = (char *) malloc ( sizeof(char) * line_length + 1);
            if (!new_line)
            {
                free(line);
                return NULL;
            }
            while (j < i)
            {
                new_line[j] = line[j];
                j++;
            }
            free(line);
            line = new_line;
        }
    }
    line[i] = '\0';
    return ft_strdup(line);
}

int main(void)
{
    int fd = open("test.txt",O_RDONLY);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    return 0;
}