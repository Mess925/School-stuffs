#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

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
static char *g_buff[FD_SETSIZE];
static int g_max = 0;
static int g_next = 0;
static fd_set g_read, g_master;

static void arg(){
	write(2, "Wrong number of arguments\n", 26);
	exit(1);
}

static void fatal(){
	write(2, "Fatal error\n", 12);
	exit(1);
}

static void send_all(int efd,char *msg){
	for(int fd = 0 ; fd <= g_max; fd++){
		if(fd != efd && g_id[fd] != -1)
			send(fd, msg,strlen(msg), 0);
	}
}

static void add_client(int sockfd){
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	int fd = accept(sockfd, (void *)&addr, &len);
	if(fd < 0 || fd >= FD_SETSIZE)
		return;

	g_id[fd] = g_next++;
	g_buff[fd] = NULL;
	if(fd > g_max)
		g_max = fd;

	FD_SET(fd, &g_master);
	char msg[64];
	sprintf(msg, "server: client %d just arrived\n", g_id[fd]);
	send_all(fd,msg);
}

static void remove_client(int fd){
	char msg[64];
	sprintf(msg, "server: client %d just left\n", g_id[fd]);
	send_all(fd, msg);

	close(fd);
	FD_CLR(fd, &g_master);
	free(g_buff[fd]);
	g_buff[fd] =  NULL;
	g_id[fd] = -1;
}

static void handle(int fd){
	char buffer[4096];
	int r = recv(fd, buffer, 4095, 0);
	if( r <= 0 ){
		remove_client(fd);
		return;
	}
	buffer[r] = 0;
	g_buff[fd] =  str_join(g_buff[fd], buffer);
	if(!g_buff[fd])
		fatal();
	char *msg;
	while(extract_message(&g_buff[fd], &msg) == 1)
	{
		char out[64];
		sprintf(out, "client %d: ", g_id[fd]);

		char *sendbuff =  malloc(strlen(out) + strlen(msg) + 1);
		if(!sendbuff)
			fatal();
		sendbuff[0] = 0;
		strcat(sendbuff, out);
		strcat(sendbuff, msg);

		send_all(fd, sendbuff);

		free(sendbuff);
		free(msg);
	}
}

int main(int ac, char **av) {
	if(ac != 2)
		arg();
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		fatal();
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (void *)&servaddr, sizeof(servaddr))) < 0)
		fatal();
	if (listen(sockfd, 128) < 0) 
		fatal();

	for(int i = 0; i < FD_SETSIZE; i++){
		g_id[i] = -1;
		g_buff[i] = NULL;
	}

	g_max = sockfd;
	FD_ZERO(&g_master);
	FD_SET(sockfd, &g_master);

	while(1){
		g_read =  g_master;
		if(select(g_max + 1, &g_read, NULL, NULL, NULL) < 0)
			continue;
		if(FD_ISSET(sockfd, &g_read))
			add_client(sockfd);
		for(int fd = 0; fd <= g_max; fd++){
			if(fd != sockfd && g_id[fd] != -1 && FD_ISSET(fd, &g_read))
				handle(fd);
		}
	}
}

