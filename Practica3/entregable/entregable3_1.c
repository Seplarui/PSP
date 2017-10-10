#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd[2];
    char buffer[30];
    pid_t pid;

    pipe(fd); //se crea el pipe
    pid=fork(); //se crea el proceso hijo

    switch(pid)
    {
        case -1: //error

        printf("No se ha podido crear el hijo\n");
        exit(-1);
        break;

        case 0: //hijo
        
        printf("el hijo envía un mensaje al padre...\n");
        write(fd[1], "Buenos dias Padre",30);
        break;

        default: //padre

        wait(NULL); //padre espera hijo termine escribir
        read(fd[0], buffer, 30);
        printf("\tMensaje leído: %s\n", buffer);
        break;
    } //fin switch
}