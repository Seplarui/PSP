#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    pid_t pid1, pid2;
    int status1, status2;

    pid1=fork();

    if (pid1==0) {
        /*HIJO*/

        printf("Soy el primer hijo (%d, hijo de %d)\n", getpid(), getppid());

    }

    else {
        /*PADRE */

        if ((pid2=fork())==0)
        {
            /* SEGUNDO HIJO */

            printf("Soy el segundo hijo (%d, hijo de %d)\n", getpid(), getppid());

        }
        else 
        {
            /* PADRE */

            /* ESPERAMOS AL PRIMER HIJO TERMINE, STATUS 0 */

            waitpid(pid1, &status1, 0);

            /* ESPERAMOS A QUE EL SEGUNDO HIJO TERMINE, STATUS 0 */

            waitpid(pid2, &status2,0);
            printf("Soy el padre (%d, hijo de %d)\n", getpid(), getppid());
        }
    }
    return 0;
}