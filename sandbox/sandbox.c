#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

#define TIMEOUT_SEC 2

// Your function (to test with sandbox)
void ft_test(void *ptr)
{
    char *str = (char *)ptr;
    while (*str)
        write(1, str++, 1);
    write(1, "\n", 1);
}


void sandbox(void *func, char *desc, void *input)
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        // In child
        void (*f)(void *) = (void (*)(void *))func;
        f(input);
        exit(0);
    }
    else
    {
        int status;
        time_t start = time(NULL);

        while (time(NULL) - start < TIMEOUT_SEC)
        {
            pid_t finished = waitpid(pid, &status, WNOHANG);
            if (finished == pid)
            {
                if (WIFEXITED(status))
                {
                    int code = WEXITSTATUS(status);
                    if (code == 0)
                        printf("[OK] %s\n", desc);
                    else
                        printf("[FAIL] %s (exit code %d)\n", desc, code);
                }
                else if (WIFSIGNALED(status))
                {
                    int sig = WTERMSIG(status);
                    printf("[CRASH] %s (signal %d: %s)\n", desc, sig, strsignal(sig));
                }
                return;
            }
            usleep(10000); // 10ms
        }

        // Timeout
        kill(pid, SIGKILL);
        printf("[TIMEOUT] %s\n", desc);
    }
}
int main(void)
{
    sandbox((void *)ft_test, "Normal string", "hello");
    sandbox((void *)ft_test, "NULL input (should crash)", NULL);
    return 0;
}
