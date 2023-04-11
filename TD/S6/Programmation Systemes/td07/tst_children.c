#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int older_child = 0;

void on_usr_receiving(int signal) {
    if(signal == SIGUSR1 && older_child != 0) {
        kill(older_child,SIGUSR2);
    }
    printf("signal %d, finishing process\n",signal);
    exit(0);
}

int main(){
    printf("test %d\n", older_child);
    struct sigaction sigact;
    sigset_t msk_sigusr1, msk_sigusr2;

    printf("test %d\n", older_child);
    switch (fork()) {
        case -1 : {
            printf("an error occured with first fork...\n");
            exit(1);
        }
        case 0 : {
            older_child = getpid();
            sigemptyset(&msk_sigusr2);  
	        sigaddset(&msk_sigusr2, SIGUSR2); 
            sigact.sa_handler = on_usr_receiving;
            sigact.sa_mask = msk_sigusr2;  
	        sigaction(SIGUSR2, &sigact, NULL); 
            while(1){}
            break;
        }
        default : {
            break;
        }
    }
    printf("test %d\n", older_child);
    int young = fork();
    switch (young) {
        case -1 : {
            printf("an error occured with second fork...\n");
            exit(1);
        }
        case 0 : {
            sigemptyset(&msk_sigusr1);  
	        sigaddset(&msk_sigusr1, SIGUSR1); 
            sigact.sa_handler = on_usr_receiving;
            sigact.sa_mask = msk_sigusr1;  
	        sigaction(SIGUSR1, &sigact, NULL); 
            while(1){}
        }
        default : {
            break;
        }
    }

    printf("test %d %d\n",young, older_child);
    kill(young, SIGUSR1);
    wait(0);
    wait(0);
    return 0;
}