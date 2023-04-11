#include <signal.h>
#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h>

int nb_SIGINT = 5;

void print_signal(int sig) {
    printf("*** signal %d\n", sig);
    if(sig == 2) {
        nb_SIGINT -= 1;
        if (nb_SIGINT == 0){
            exit(0);
        }
    }
    else if (sig == 11) {
        nb_SIGINT = 5;
    }
}

int main() {
    signal(SIGSEGV,print_signal);
    signal(SIGINT,print_signal);
    
    while(1){}
}