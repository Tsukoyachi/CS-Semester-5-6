#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

//This code create a temporary zombie...
int main() {
    switch(fork()) {
        case -1 :
            perror("fork");
            exit(1);
        case 0 :
            printf("%d",getpid());
            break;
       default :
            sleep(30);
            break;
    }
    //Don't make a wait for the father to be sure that the child will be a zombie
    return 0;
}