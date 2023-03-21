#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>


void print_fileinfo(char *filepath) {
    struct stat file;
    stat(filepath,&file);

    printf("%d\n",file.st_mode);
}

void list(char *directory) {
    DIR *dir;
    struct dirent *file;

    if(!is_dir(directory)) {
        print_fileinfo(directory);
        return;
    }
    dir = opendir(directory);

    while ((file = readdir(dir)) != NULL){
        char *filepath = (char *) malloc(sizeof(char)*(strlen(directory)+ strlen(file->d_name)));
        if(filepath == NULL){
            printf("Allocation error...\n");
            exit(1);
        }
        snprintf(filepath,(strlen(directory)+ strlen(file->d_name)), "%s/%s", directory, file->d_name);
        if(!is_dir(file)){
            print_fileinfo(filepath);
        }
        else {
            printf("%s\n",file->d_name);
            if(!is_dot_dir(file)){
                list(filepath);
            }
        }
    }

    closedir(dir);

}

int main(int argc, char *argv[]){
    for(int i = 1; i < argc; i++){
        list(argv[i]);
    }

    return 0;
}