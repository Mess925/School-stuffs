# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int main(void){
    int fd = open("test.txt", O_WRONLY);
    dup2(fd, STDOUT_FILENO);
    printf("HI\n");
}
