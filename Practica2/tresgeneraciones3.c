#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
pid_t pid1, pid2, pid3;
int status1, status2, status3;
if((pid1=fork()) == 0)
{
        
    if((pid2=fork()) == 0)
    {    
            printf("1-Soy el nieto (%d, hijo de %d)\n", getpid(), getppid());
    }else if( pid2 > 0){
            waitpid(pid2, &status2, 0);
            printf("2-Soy el hijo (%d, hijo de %d)\n", getpid(), getppid());

        }    

}
else
{    
    waitpid(pid1, &status1, 0);

    printf("3-Soy el abuelo (%d, hijo de %d)\n",getpid(), getppid());
}

return 0;
}