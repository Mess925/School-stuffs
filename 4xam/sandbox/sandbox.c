
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int g_to;

void handle_timeout(int sig)
{
    if (SIGALRM == sig)
        g_to = 1;
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
    int status;
    pid_t pid;
    struct sigaction sa;

    pid = fork();
    if (pid == -1)
        return (-1);
    if (pid == 0)
    {
        f();
        exit(0);
    }
    sa.sa_handler = handle_timeout;
    sigaction(SIGALRM, &sa, NULL);
    alarm(timeout);
    if (waitpid(pid, &status, 0) == -1)
    {
        while (1)
        {
            if (errno == EINTR)
            {
                if (g_to)
                {
                    if (verbose)
                        printf("Bad function: timed out in %u seconds\n", timeout);
                    kill(pid, SIGKILL);
                    if (waitpid(pid, &status, 0) == -1)
                        return (-1);
                    return (0);
                }
                continue;
            }
            else
                return (-1);
            break;
        }
    }
    if (WIFSIGNALED(status))
    {
        int exit_code = WTERMSIG(status);
        if (verbose)
            printf("Bad function: %s\n", strsignal(exit_code));
        return (0);
    }
    if (WIFEXITED(status))
    {
        int exit_code = WEXITSTATUS(status);
        if (exit_code)
        {
            if (verbose)
                printf("Bad function: exited with code %d\n", exit_code);
            return (0);
        }
        else
        {
            if (verbose)
                printf("Nice function!\n");
            return (1);
        }
    }
    return (-1);
}

void bad_function(void)
{
    exit(42);
}

void good_function(void)
{
}

int main()
{
    printf("Testing a good function\n");
    sandbox(good_function, 3, true);

    printf("Testing a bad function\n");
    sandbox(bad_function, 3, true);

    return (0);
}