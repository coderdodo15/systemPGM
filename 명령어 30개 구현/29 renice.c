#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr,
                "Usage: %s <nice_value> <pid>\n",
                argv[0]);
        return 1;
    }

    int nice_val = atoi(argv[1]);
    pid_t pid = atoi(argv[2]);

    if (setpriority(PRIO_PROCESS,
                    pid,
                    nice_val) == -1)
    {
        perror("setpriority");
        return 1;
    }

    printf("PID %d priority changed to %d\n",
           pid,
           nice_val);

    return 0;
}
