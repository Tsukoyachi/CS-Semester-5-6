#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void lecture(int fd) {
    char c;
    while(read(fd,&c,1) && c != EOF){
        write(0,&c,1);
    }
    printf("\n");
}

int main(){
    int pipefd[2];
    int pipeResult = pipe(pipefd);
    if(pipeResult == -1){
        printf("Error with pipe...\n");
        exit(1);
    }

    switch(fork()) {
        case -1 : {
            printf("Error with fork...\n");
            exit(1);
        }
        case 0 : {
            close(pipefd[1]);
            lecture(pipefd[0]);
            close(pipefd[0]);
            exit(0);
        }
        default : {
            close(pipefd[0]);
            int writtedChar = write(pipefd[1],"0123456789", 10*sizeof(char));
            close(pipefd[1]);

            if(writtedChar <= 0) {
                printf("An error occured with the writing...\n");
                exit(1);
            }
        }
    }
    return 0;
}