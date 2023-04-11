#include <signal.h>
#include <stdio.h>

void on_usr_receiving(int signal) {
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
}