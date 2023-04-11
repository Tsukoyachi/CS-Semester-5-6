#include <signal.h>
#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h>

int nb_SIGINT = 5;

void print_signal(int sig) {
    printf("*** signal %d\n", sig);
    if(sig == SIGINT) {
        nb_SIGINT -= 1;
        if (nb_SIGINT == 0){
            exit(0);
        }
    }
    else {
        nb_SIGINT = 5;
    }
}

int main() {
    struct sigaction sigact; 
    sigset_t msk_int, msk_segv;
    sigemptyset(&msk_int);  
	sigaddset(&msk_int, SIGINT);  
    sigemptyset(&msk_segv);  
	sigaddset(&msk_segv, SIGSEGV);  
    sigact.sa_handler = print_signal;  
	sigact.sa_mask = msk_segv;  
	sigaction(SIGINT, &sigact, NULL);  
	sigact.sa_mask = msk_int;  
	sigaction(SIGSEGV, &sigact, NULL);  
    while(1){}
}