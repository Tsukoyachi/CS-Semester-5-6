#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "timer.h"

#define NTHREADS 4000

void *wait_threads(void *arg){
    sleep(10);
    pthread_exit((void *) 0);
}

long create_thread(long n) {

    pthread_t *t = (pthread_t *) malloc(sizeof(pthread_t)*n);
    if(t == NULL){
        printf("Allocation error...");
        exit(1);
    }
    struct timespec vartime = timer_start(); /* Démarrage de la mesure temporelle */
    /* Création de n thread s'exécutant en parallèle */
    for (int i = 0; i < n; ++i) {
        pthread_create(&t[i],NULL,&wait_threads,NULL);
	}

    /* On mesure le temps écoulé pour la création des n processus */
	long time = timer_end(vartime);

     for (int i = 0; i < n; ++i) {
        pthread_join(t[i],NULL);
	}

	return time;
}

int main(int argc, char *argv[]) {
	int n = NTHREADS;

    long time_processus = create_thread(n);
	
	printf("Time taken for creating %d threads (nanoseconds): %ld\n", n, time_processus);
	printf("Time taken for creating %d threads (milliseconds): %ld\n", n, time_processus / NANO_TO_MILLI);

    /* On flushe la sortie standard */
    fflush(stdout);

    /* Fin du père */
    exit(0);
}

