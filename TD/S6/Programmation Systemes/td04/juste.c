/*	                                              -*- coding: utf-8 -*-
 * Un exemple avec des threads qui marche (presque)
 *
 *           Author: Erick Gallesio [eg@unice.fr]
 *    Creation date: 28-Apr-2010 21:40 (eg)
 * Last file update:  5-May-2011 19:52 (eg)
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 5

void *func(void *arg)
{
    sleep(1 + rand() % 5);
	
    long n = *(long*) arg;

    printf("Dans la thread #%ld\n", n);
	
    return NULL;
}

int main()
{
    long i;
    pthread_t threads[MAX];
    long arg[MAX];

    /* Creation des threads */
    for (i = 0; i < MAX; i++) {
        /*On stock l'argument dans un tableau pour la case du tableau ait une adresse distincte 
        de celle des autres arguments de la boucle pour que la valeur ne change pas d'un passage de boucle à l'autre */
        arg[i] = i;
        pthread_create(&threads[i], NULL, func, (void *)&arg[i]);
    }

    /* On attend que ça se termine */
    for (i = 0; i < MAX; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
