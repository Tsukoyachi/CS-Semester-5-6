#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lecture(int fd) {
    char c[3];
    int readedChar;
    while(readedChar = read(fd,&c,3) && !strchr(c,EOF)){
        write(0,c,readedChar);
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
            close(pipefd[0]);
            switch (fork()) {
                case -1 :{
                    printf("An error occured with the fork");
                    exit(1);
                }
                case 0 : {
                    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTVUWXYZ";
                    for(int i = 0; i<strlen(alphabet); i+=2) {
                        int writtenChar = write(pipefd[1],alphabet+i,2);
                        if(writtenChar <= 0){
                            printf("An error occured with the writing...\n");
                            exit(1);
                        }
                        sleep(1);
                    }
                    close(pipefd[1]);
                }
                default:{
                        char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
                        for(int i = 0; i<strlen(alphabet); i+=2) {
                            int writtenChar = write(pipefd[1],alphabet+i,2);
                            if(writtenChar <= 0){
                                printf("An error occured with the writing...\n");
                                exit(1);
                            }
                            sleep(1);
                        }
                        close(pipefd[1]);
                    }
            }
        }
        default : {
            close(pipefd[1]);
            lecture(pipefd[0]);
            close(pipefd[0]);
            exit(0);
        }
    }
    return 0;
}