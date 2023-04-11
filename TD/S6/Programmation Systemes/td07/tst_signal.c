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
    signal(SIGSEGV,print_signal);
    signal(SIGINT,print_signal);
    
    while(1){}
}