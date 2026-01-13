#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>

/* ================= SOCKET ================= */

class Socket {
private:
    int _fd;
    struct sockaddr_in addr;

public:
    Socket() : _fd(-1) {}

    ~Socket()
    {
        if (_fd != -1)
            close(_fd);
    }

    void create(int port)
    {
        _fd = socket(AF_INET, SOCK_STREAM, 0);
        if (_fd < 0)
            exit(1);

        bzero(&addr, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
        addr.sin_port = htons(port);
    }

    void listenAndBind()
    {
        if (bind(_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
            exit(1);
        if (listen(_fd, 128) < 0)
            exit(1);
    }

    int acceptClient()
    {
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        return accept(_fd, (struct sockaddr *)&client, &len);
    }

    int fd() const { return _fd; }
};

/* ================= SERVER ================= */

class Server {
private:
    Socket sock;
    fd_set master;
    fd_set readfds;
    int maxfd;

public:
    void run(int port)
    {
        try
        {
            sock.listenAndBind();

            FD_ZERO(&master);
            FD_SET(sock.fd(), &master);
            maxfd = sock.fd();

            while (1)
            {
                readfds = master;
                if (select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0)
                    continue;

                // YOU MUST IMPLEMENT:
                // - accept new clients
                // - recv commands
                // - parse POST / GET / DELETE
                // - send responses
                // - save database on disconnect
            }
        }
        catch (...)
        {
            exit(1);
        }
    }
};

/* ================= MAIN ================= */

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(2, "Wrong number of arguments\n", 26);
        return 1;
    }

    Server server;
    server.run(atoi(argv[1]));
    return 0;
}
