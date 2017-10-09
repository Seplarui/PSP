#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int status1, status2;

    pid_t pid1, pid2;


    pid1 = fork();

    if (pid1 == 0)
    {
        // ESTAMOS EN EL HIJO

        printf("Soy el hijo (%d, hijo de %d)\n", getpid(), getppid());
    }
    else
    {

        if ((pid2 == fork()) == 0)
        {
            // ESTAMOS EN EL NIETO

            printf("Soy el nieto (%d, hijo de %d)\n", getpid(), getppid());
        }

        else
        {
            // ESPERAMOS A QUE TERMINE EL HIJO
            waitpid(pid1, &status1, 0);

            // ESPERAMOS A QUE TERMINE EL NIETO

            waitpid(pid2, &status2, 0);

            printf("Soy el abuelo(%d, hijo de %d)\n", getpid(), getppid());
        }
    }

    return 0;
}
