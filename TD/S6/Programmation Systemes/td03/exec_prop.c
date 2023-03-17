#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    //Test buffer sharing between father and child process
    //We see that "test without flush" is printed twice, one for the father and one for the child
    printf("test without flush");
    int statut = 0;
    switch(fork()) {
        case -1 :
            perror("fork");
            exit(1);
        case 0 :
            printf("blabla \n");
            exit(0);
        default :
            break;
    }
    wait(&statut);
    printf("\n");


    //To compare the pid with the execlp's pid
    printf("father pid : %d\n",getpid());

    //Test buffer not sharing between father and child process
    //We see that the "test without flush" isn't being printed because the execlp replace the previous buffer.
    printf("test without flush");
    execlp("./exec_prop-aux.exe", "exec_prop-aux", "coucou", NULL);


    //Not reached
    printf("Can't be reached because of the exec...");

    return 0;
}