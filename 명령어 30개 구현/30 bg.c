#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int bg(pid_t pid)
{
    if (kill(pid, SIGCONT) == -1)
    {
        perror("SIGCONT");
        return -1;
    }

    printf("[%d] running in background\n", pid);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);

    bg(pid);

    return 0;
}
