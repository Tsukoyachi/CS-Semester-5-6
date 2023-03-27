#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>
#include "util.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

int main() {
    int fd_file = open("./fd_herit_file", O_RDONLY);
    DIR *dir = opendir(".");
    char *firstFile = readdir(dir) -> d_name;
    rewinddir(dir);
    switch(fork()) {
        case -1 : {
            printf("An error occured...\n");
            exit(1);
        }
        case 0 : {
            char text[BUFFER_SIZE] = {};
            int readSize = read(fd_file,text,BUFFER_SIZE);
            if(readSize == 0){
                printf("An error occured...\n");
                exit(1);
            }
            printf("%s\n",text);
            if(strcmp(readdir(dir) -> d_name,firstFile) == 0){
                printf("We have acces to the same open directory \n");
            }
            else {
                printf("An error occured with the open directory...\n");
                exit(1);
            }
            exit(0);
        }
        default : {
            wait(0);
            break;
        }
    }

    return 0;
}