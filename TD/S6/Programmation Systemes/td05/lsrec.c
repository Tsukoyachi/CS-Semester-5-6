#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>


void list(char *directory) {
    DIR *dir;
    struct dirent *file;

    if(!is_dir(directory)) {
        print_fileinfo(directory);
        return;
    }
    dir = opendir(directory);

    while ((file = readdir(dir)) != NULL){
        char *filepath = (char *) malloc(sizeof(char)*(strlen(directory)+ strlen(get_basename(file))));
        if(filepath == NULL){
            printf("Allocation error...\n");
            exit(1);
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