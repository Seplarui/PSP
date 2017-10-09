#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    pid_t pid1, pid2, pid3;

    int status1, status2;

    pid1=fork();

    if(pid1==0) {
        /* ABUELO */

        printf ("Soy el abuelo (%d)\n", getpid(), getppid());


    } else {

        if((pid2=fork())==0)
        {
            printf("Soy el hijo (%d, hijo de %d)\n", getpid(), getppid());
        }

        else {
            /* Esperamos que el hijo termine */
         /*  waitpid(pid1, &status2, 0);
            
            waitpid(pid2, &status1, 0);*/

            
            printf("Soy el nieto(%d, hijo de %d)\n",getpid(), getppid());

            waitpid(pid1, &status2, 0);
            
            waitpid(pid2, &status1, 0);
        }

    }
    
    return 0;
}