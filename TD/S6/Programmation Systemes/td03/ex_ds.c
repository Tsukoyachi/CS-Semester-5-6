#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("We need at least two argument for the filepath of the start and end file...\n");
        exit(1);
    }

    int pipes[2];
    pipe(pipes);

    switch(fork()) {
        case -1 : {
            printf("An error occured...\n");
            exit(1);
        }
        case 0 : {
            int fd = open(argv[1], O_RDONLY, 0777);
            close(pipes[0]);
            char c;
            while(read(fd,&c,1*sizeof(char)) > 0) {
                c = toupper(c);
                write(pipes[1],&c,1*sizeof(char));
            }
            close(pipes[1]);
            close(fd);
            exit(0);
        }
        default : {
            close(pipes[1]);
            int fd2 = open(argv[2], O_TRUNC | O_CREAT | O_WRONLY, 0777);
            char c2;
            while(read(pipes[0],&c2,1*sizeof(char))>0){
                write(fd2,&c2,1*sizeof(char));
            }
            close(pipes[0]);
            close(fd2);
        }
    }
    return 0;
}