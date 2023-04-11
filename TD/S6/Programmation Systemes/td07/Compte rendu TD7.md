## Exercice 1
---

1. La commande xeyes, le terminal est bloqué.
2. Après un Ctrl+Z, xeyes est suspendu, toujours ouvert mais on a de nouveau accès au terminal.
3. La commande xeyes est listé parmis les tâches en arrière plan.
![[Pasted image 20230411092128.png]]
4. Le PID de xeyes est 8157. 
   ![[Pasted image 20230411092435.png]]
5. Après une exécution de kill -SIGSTOP 8157 dans une autre instance du terminal rien ne se passe. SIGSTOP est équivalent à Ctrl+Z puisqu'il permet de mettre une suspendre une tâche et de la mettre en arrière plan.
6. Le signal correspondant est SIGCONT et je l'ai envoyé avec la commande kill -18 pid où pid correspond à la commande xeyes.
   ![[Pasted image 20230411092957.png]]
   ![[Pasted image 20230411093040.png]]
7. J'ai utilisé killall xeyes afin de stopper son exécution sans utiliser son PID.
   ![[Pasted image 20230411093433.png]]

## Exercice 2
---
```c
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
    // On capture les signaux afin d'exécuter la fonction print_signal dès leur capture
    signal(SIGSEGV,print_signal);
    signal(SIGINT,print_signal);
    
    while(1){}
}
```


## Exercice 3
---
```c
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
```