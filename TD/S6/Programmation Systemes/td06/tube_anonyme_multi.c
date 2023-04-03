#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void lecture(int fd) {
    char c[4];
    int readedChar;
    while((readedChar = read(fd, c, 3)) > 0){
        c[readedChar] = '\0';
        printf("%s", c);
        fflush(stdout);
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

    pid_t pid1 = fork();

    if (pid1 == -1) {
        printf("Error with fork...\n");
        exit(1);
    }

    if (pid1 == 0) {
        close(pipefd[0]);
        char alphabet[] = "ABCDEFGHIJKLMNOPQRSTVUWXYZ";
        for(size_t i = 0; i < strlen(alphabet); i += 2) {
            int writtenChar = write(pipefd[1], &alphabet[i], 2);
            if(writtenChar <= 0){
                printf("An error occured with the writing...\n");
                exit(1);
            }
            sleep(1);
        }
        close(pipefd[1]);
        exit(0);
    }

    pid_t pid2 = fork();

    if (pid2 == -1) {
        printf("Error with fork...\n");
        exit(1);
    }

    if (pid2 == 0) {
        close(pipefd[0]);
        char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
        for(size_t i = 0; i < strlen(alphabet); i += 2) {
            int writtenChar = write(pipefd[1], &alphabet[i], 2);
            if(writtenChar <= 0){
                printf("An error occured with the writing...\n");
                exit(1);
            }
            sleep(1);
        }
        close(pipefd[1]);
        exit(0);
    }

    close(pipefd[1]);
    lecture(pipefd[0]);
    close(pipefd[0]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}