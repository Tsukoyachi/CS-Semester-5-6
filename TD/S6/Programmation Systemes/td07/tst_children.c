#include <signal.h>
#include <stdio.h>

pid_t older_child = NULL;

void on_usr_receiving(int signal) {
    if(signal == SIGUSR1 && older_child != NULL) {
        kill(older_child,SIGUSR2);
    }
    printf("signal %d, finishing process\n");
    exit(0);
}

int main(){
    struct sigaction sigact;
    sigset_t msk_sigusr1, msk_sigusr2;

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

    switch (fork()) {
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
            break;
        }
        default : {
            break;
        }
    }
}