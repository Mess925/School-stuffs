#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

static int g_id[FD_SETSIZE];
static char *g_buf[FD_SETSIZE];
static int g_next = 0;
static int g_max = 0;
static int fd_set, g_read, g_master;

int main(int ac, char **av) {
    if(ac != 2)
        return -1;

	int sockfd;
	struct sockaddr_in servaddr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");
	if (listen(sockfd, 128) != 0) {
		printf("cannot listen\n");
		exit(0);
	}
    
    for(int i = 0; i < FD_SETSIZE; i++){
        g_id[i] = -1;
        g_buf[i] = NULL;
    }

    g_max = sockfd;
    FD_ZERO(&g_master);
    FD_SET(sockfd, &g_master);

    while(1){
        g_read = g_master;
        if(select(g_max + 1, &g_read, NULL, NULL, NULL) < 0)
            continue;
        if(FD_ISSET(sockfd, &g_read))
            add_client(sockfd);
        for(int fd =0; fd < g_max; fd++){
            if(fd != sockfd && g_id[fd] != -1 && FD_ISSET(fd, &g_reaa
            ))
                handle(fd);
        }
    }

	len = sizeof(cli);
	connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
	if (connfd < 0) {
		printf("server acccept failed...\n");
		exit(0);
	}
	else
		printf("server acccept the client...\n");
}