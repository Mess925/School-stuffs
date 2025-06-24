
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

static void do_nothing(int sig)
{
    (void)sig; // unused parameter
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
    pid_t pid = fork();
    if (pid == -1)
        return -1;

    if (pid == 0)
    {
        alarm(timeout);
        f();
        exit(0);
    }

    struct sigaction sa;
    sa.sa_handler = do_nothing;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGALRM, &sa, NULL) == -1)
        return -1;

    alarm(timeout);

    int status;
    pid_t r = waitpid(pid, &status, 0);
    if (r == -1)
    {
        if (errno == EINTR)
        {
            kill(pid, SIGKILL);
            waitpid(pid, NULL, 0);
            if (verbose)
                printf("Bad function: timed out after %u seconds\n", timeout);
            return 0;
        }
        return -1;
    }

    if (WIFEXITED(status))
    {
        int exit_code = WEXITSTATUS(status);
        if (exit_code == 0)
        {
            if (verbose)
                printf("Nice function!\n");
            return 1;
        }
        else
        {
            if (verbose)
                printf("Bad function: exited with code %d\n", exit_code);
            return 0;
        }
    }
    else if (WIFSIGNALED(status))
    {
        int sig = WTERMSIG(status);
        if (sig == SIGALRM)
        {
            if (verbose)
                printf("Bad function: timed out after %u seconds\n", timeout);
            return 0;
        }
        else
        {
            if (verbose)
                printf("Bad function: terminated by signal %s\n", strsignal(sig));
            return 0;
        }
    }
    return -1;
}


void bad_function(void)
{
    exit(42);
}

void good_function(void)
{
}

void cancel_alarm(void)
{
	struct sigaction ca;
	ca.sa_handler = SIG_IGN;
	sigaction(SIGALRM, &ca, NULL);

	sleep(5);
	printf("f waited 5 seconds, should be terminated before by alarm set in parent process if timeout < 5\n");
}

int main()
{
    printf("Testing a good function\n");
    sandbox(good_function, 3, true);

    printf("Testing a bad function\n");
    sandbox(bad_function, 3, true);
    sandbox(cancel_alarm, 3, true);
    return (0);
}