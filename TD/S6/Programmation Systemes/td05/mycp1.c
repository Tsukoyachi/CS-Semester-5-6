#include "util.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

void cpFileInFile(char *fileStart, char *fileDest) {
    if(!file_exists(fileStart)){
        printf("Start file doesn't exist...\n");
        exit(1);
    }
    int fd_fileStart = open(fileStart,O_RDONLY);
    int fd_fileDest = open(fileDest,O_TRUNC | O_CREAT | O_WRONLY | S_IWGRP);
    
    if(fd_fileStart == -1 || fd_fileDest == -1) {
        printf("An error occured with the file(s) opening\n");
        exit(1);
    }

    int readedChar = 0;
    char buffer[BUFFER_SIZE] = {};
    while((readedChar = read(fd_fileStart,buffer,BUFFER_SIZE)) > 0) {
        if(readedChar != write(fd_fileDest,buffer,readedChar)){
            printf("Error in writing...\n");
        }
    }

    close(fd_fileStart);
    close(fd_fileDest);
}

void cpFilesInDirectory(int argc, char *files[]){
    if(argc < 3 || !is_dir(files[1])){
        printf("Requirements of this method aren't respected...\n");
        exit(1);
    }
    for(int i = 2; i<argc ;i++){
        char *fileDest = (char *) malloc(sizeof(char)*(strlen(files[1])+ strlen(get_basename(files[i]))+2));
        snprintf(fileDest,(strlen(files[1])+ strlen(get_basename(files[i]))) + 2, "%s/%s", files[1], get_basename(files[i]));
        cpFileInFile(files[i],fileDest);
        free(fileDest);
    }
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        return 0;
    }

    if (argc == 3 && !is_dir(argv[1])) {
        cpFileInFile(argv[1], argv[2]);
    }
    else if (argc >= 3 && is_dir(argv[1])){
        cpFilesInDirectory(argc, argv);
    }
    else {
        return 1;
    }

    return 0;
}