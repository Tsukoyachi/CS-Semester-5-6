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
           for(int j = 0; j < 10; j++){
                printf("child : %d; father : %d\n",getpid(),getppid());
                sleep(30); //Long sleep to keep the child alive
            }
            exit(0);
            break;
       default :
            break;
    }
    //Don't make a wait for the father to be sure that the child will be a zombie
    return 0;
}