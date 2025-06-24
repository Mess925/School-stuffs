#include <unistd.h>
#include <stdlib.h>

int	ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || (type != 'r' && type != 'w'))
		return -1;

	int fd[2];
	int status;

	pipe(fd);
	if (type == 'r')
	{
		if (fork() == 0)
		{
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			execvp(file, argv);
			exit (-1);
		}
		close(fd[1]);
		return (fd[0]);
	}
	if (type == 'w')
	{
		if (fork() == 0)
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			close(fd[1]);
			execvp(file, argv);
			exit (-1);
		}
		close(fd[0]);
		return (fd[1]);
	}
	return -1;
}
// #include <fcntl.h>
// #include <stdio.h>
// #include <string.h>

// // int main()
// // {
// // 	//int fd = open("texte", O_RDONLY);
// // 	int fd = ft_popen("ls", (char *const[]){"ls", NULL}, 'r');

// // 	char buf[1];
// // 	while(read(fd, buf, 1))
// // 		write(1, buf, 1);

// // 	close(fd);
// // 	return (0);
// // }

// //test type 'w'
// int main()
// {
//     int fd = ft_popen("wc", (char *const[]){"wc", NULL}, 'w');
// 	if (fd == -1)
// 	{
// 		perror("error ft_popen args");
// 		return (0);
// 	}

//     char *input = "Hello world\nThis is a test\nthird line mofo\n";
//     write(fd, input, strlen(input));
	

//     close(fd);
// 	printf("after test\n");
//     return (0);
// }