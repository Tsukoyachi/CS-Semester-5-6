#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <time.h>


void print_fileinfo(char *filepath) {
    struct stat file;
    stat(filepath,&file);
    struct passwd * infoUser = getpwuid(file.st_uid);
    struct passwd * infoGroup = getpwuid(file.st_gid);

    time_t time = file.st_mtime;
    char s[1024];
    strftime(s, sizeof(s), "%d %B %H:%M", localtime(&time));

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
    printf("%ld %s %s\n", file.st_blksize, s, get_basename(filepath));
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
        char *filepath = (char *) malloc(sizeof(char)*(strlen(directory)+ strlen(file->d_name) +2));
        if(filepath == NULL){
            printf("Allocation error...\n");
            exit(1);
        }
        snprintf(filepath,(strlen(directory)+ strlen(file->d_name)) + 2, "%s/%s", directory, file->d_name);
        print_fileinfo(filepath);
        free(filepath);
    }

    rewinddir(dir);

    while ((file = readdir(dir)) != NULL) {
        char *filepath = (char *) malloc(sizeof(char)*(strlen(directory)+ strlen(file->d_name) +2));
        if(filepath == NULL){
            printf("Allocation error...\n");
            exit(1);
        }
        snprintf(filepath,(strlen(directory)+ strlen(file->d_name)) + 2, "%s/%s", directory, file->d_name);
        if(is_dir(filepath)) {
            if(!is_dot_dir(file->d_name)){
                printf("\n--------------dossier %s----------------\n",file->d_name);
                list(filepath);
            }
        }
        free(filepath);
    }
    closedir(dir);
}

int main(int argc, char *argv[]){
    for(int i = 1; i < argc; i++){
        list(argv[i]);
    }

    return 0;
}