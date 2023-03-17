#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    //We'll create 10 fork where we'll print the order number of the fork 10 time
    int status;

    for(int i = 0; i<10; i++){
        switch(fork()) {
            case -1 :
                perror("fork");
                exit(1);
            case 0 :
                for(int j = 0; j < 10; j++){
                    printf("%d\n",getpid());
                    sleep(1);
                }
                exit(0);
                break;
            default :
                break;
        }
    }
    // To avoid zombie we need to wait for them before killing the father's process
    for(int y = 0;y<10;y++){
        wait(&status);
    }
    return 0;
}