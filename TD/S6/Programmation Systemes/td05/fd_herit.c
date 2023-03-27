#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

int main() {
    int fd = open("./fd_herit_file.txt", O_RDONLY);
    switch(fork()) {
        case -1 : {
            printf("An error occured...\n");
            exit(1);
        }
        case 0 : {
            char text[BUFFER_SIZE] = {};
            int readSize = read(fd,text,BUFFER_SIZE);
            if(readSize == 0){
                printf("An error occured...\n");
                exit(1);
            }
            write(1,text,readSize);
            exit(0);
        }
        default : {
            wait(0);
            break;
        }
    }

    return 0;
}