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
    // On créé la structure sigaction qui va être en charge de gérer les signaux
    struct sigaction sigact; 
    // Les mask vont servir à masquer le signal
    sigset_t msk_int, msk_segv;
    // Chaque mask est d'abord initialisé à l'ensemble vide pour qu'ensuite on lui ajoute le signal en question.
    sigemptyset(&msk_int);  
	sigaddset(&msk_int, SIGINT);  
    sigemptyset(&msk_segv);  
	sigaddset(&msk_segv, SIGSEGV);  
    // On ajoute un handler qui sera exécuté lorsque l'on catch l'un des signaux
    sigact.sa_handler = print_signal;  
    // On ajoute le SIGSEGV
	sigact.sa_mask = msk_segv;  
	sigaction(SIGSEGV, &sigact, NULL);  
    // On ajoute le SIGINT
	sigact.sa_mask = msk_int;  
	sigaction(SIGINT, &sigact, NULL);  
    
    while(1){}
}