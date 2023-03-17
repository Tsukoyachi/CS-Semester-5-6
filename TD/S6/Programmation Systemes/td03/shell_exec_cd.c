#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int statut = 0;

    printf("Execution of who : \n");
    switch (fork())
    {
    case -1 :
        perror("fork");
        exit(1);

    case 0:
        execlp("/bin/who","who",NULL);
        break;

    default:
        wait(&statut);
        break;
    }

    printf("Execution of cd\n");
    chdir(getenv("HOME"));

    printf("Execution of ls -ls :\n");
    switch (fork())
    {
        case -1 :
            perror("fork");
            exit(1);

        case 0:
            execlp("/bin/ls","ls","-ls",NULL);
            break;

        default:
            wait(&statut);
            break;
    }

    return 0;
}