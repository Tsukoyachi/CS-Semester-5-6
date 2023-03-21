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
    struct passwd * infoUser = getpwuid(file.st_uid);
    struct passwd * infoGroup = getpwuid(file.st_gid);

    printf((S_ISDIR(file.st_mode)) ? "d" : "-");
    printf((file.st_mode & S_IRUSR) ? "r" : "-");
    printf((file.st_mode & S_IWUSR) ? "w" : "-");
    printf((file.st_mode & S_IXUSR) ? "x" : "-");
    printf((file.st_mode & S_IRGRP) ? "r" : "-");
    printf((file.st_mode & S_IWGRP) ? "w" : "-");
    printf((file.st_mode & S_IXGRP) ? "x" : "-");
    printf((file.st_mode & S_IROTH) ? "r" : "-");
    printf((file.st_mode & S_IWOTH) ? "w" : "-");
    printf((file.st_mode & S_IXOTH) ? "x" : "-");
    printf(" %ld %s %s ", file.st_nlink, infoUser->pw_name, infoGroup->pw_name);
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
        if(!is_dir(file->d_name)){
            print_fileinfo(filepath);
        }
        else {
            printf("%s\n",file->d_name);
            if(!is_dot_dir(file->d_name)){
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