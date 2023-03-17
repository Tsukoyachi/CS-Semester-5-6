#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <sys/types.h>

void *thread_print(void *arg) {
    int sleepTime = atoi(arg);
    for(int i = 0; i<5;i++){
        printf("PID number : %d | Posix thread identifier : %ld\n",getpid(),pthread_self());
        printf("Linux Thread ID: %ld\n", syscall(SYS_gettid));
        sleep(sleepTime);
    }
    pthread_exit((void *) 0);
}

int main(int argc, char *argv[]) {
    if(argc < 3){
        printf("Not enough parameter, we need 2 integer...\n");
        exit(1);
    }

    pthread_t t1, t2;
    long return1,return2;
    printf("My PID number : %d\n",getpid());
    pthread_create(&t1,NULL,&thread_print,argv[1]);
    pthread_create(&t2,NULL,&thread_print,argv[2]);
    pthread_join(t1,(void *) &return1);
    pthread_join(t2,(void *) &return2);
    printf("Execution status for first thread : %ld\n",return1);
    printf("Execution status for second thread : %ld\n",return2);
    return 0;
}

