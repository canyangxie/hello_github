#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

int testFork(void)
{
    int i = 0;
    int num = 5;

    for (i = 0; i < num; i++)
    {
        pid_t pid = fork();
        if(pid == 0)
        {
            break;
        }
    }

    if (i < num)
    {
        printf("This is a child process, pid = %d, ppid = %d\n", getpid(), getppid());
        sleep(10);
    }
    if (i == num)
    {
        printf("This is a patent process, pid = %d, ppid = %d\n", getpid(), getppid());
        sleep(20);
    }

    return 0;
}

int main (int argc, const char * argv[])
{
    testFork();
    return 0;
}
