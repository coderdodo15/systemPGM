#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr,
                "Usage: %s <nice_value> <command> [args...]\n",
                argv[0]);
        return 1;
    }

    int nice_val = atoi(argv[1]);

    if (nice(nice_val) == -1)
    {
        perror("nice");
        return 1;
    }

    execvp(argv[2], &argv[2]);

    perror("execvp");
    return 1;
}
