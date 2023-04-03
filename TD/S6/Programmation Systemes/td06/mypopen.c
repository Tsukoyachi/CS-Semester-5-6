#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

int main(int argc, char *argv[]) {

    if(argc < 2){
        printf("You forget to put a command in parameter...\n");
        exit(1);
    }
    int pipes[2];
    if(pipe(pipes) == -1){
        printf("An error occured with the pipe...\n");
        exit(1);
    }

    int tmpStandardFd = dup(1);

    switch(fork()) {
        case -1 : {
            printf("An error occured with the fork...\n");
            exit(1);
        }
        case 0 : {
            dup2(pipes[1],1);
            execv("/bin/sh", "sh", "-c", &(argv[1]));
            exit(0);
        }
        default : {
            wait(0);
        }
    }
    char buffer[1024];
    int readedChar = read(pipes[0],&buffer,BUFFER_SIZE);
    if(readedChar < 0){
        printf("A problem occured with the reading...\n");
        exit(1);
    }
    dup2(tmpStandardFd,1);
    write(tmpStandardFd,&buffer,readedChar);
    printf("\n This command's result is %d character long",readedChar);

    return 0;
}