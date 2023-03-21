#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>
#include <time.h>

#include "util.h"

#define BUFFER_SIZE 1024
#define NORMAL_COLOR  "\x1B[0m"
#define GREEN  "\x1B[32m"
#define BLUE  "\x1B[35m"
#define BG_GREEN "\e[42;1m"
#define BG_NORMAL "\e[0m"

char *joinFile(char *file1, char *file2){
    int sizeJoint = (strlen(file1)+strlen(file2)+2);
    char *buf = malloc(sizeJoint*sizeof(char));

    if(buf==NULL)
        return NULL;

    snprintf(buf,sizeJoint,"%s/%s",file1,file2);
    return buf;
}

void print_fileinfo(char *pathfile){
    struct stat sb;

    if(stat(pathfile,&sb)==-1){
        printf("Cannot get date for %s\n",pathfile);
    }

    printf( (S_ISDIR(sb.st_mode)) ? "d" : "-");
    printf( (sb.st_mode & S_IRUSR) ? "r" : "-");
    printf( (sb.st_mode & S_IWUSR) ? "w" : "-");
    printf( (sb.st_mode & S_IXUSR) ? "x" : "-");
    printf( (sb.st_mode & S_IRGRP) ? "r" : "-");
    printf( (sb.st_mode & S_IWGRP) ? "w" : "-");
    printf( (sb.st_mode & S_IXGRP) ? "x" : "-");
    printf( (sb.st_mode & S_IROTH) ? "r" : "-");
    printf( (sb.st_mode & S_IWOTH) ? "w" : "-");
    printf( (sb.st_mode & S_IXOTH) ? "x" : "-");

    struct passwd * infoUser = getpwuid(sb.st_uid);
    struct passwd * infoGroup = getpwuid(sb.st_gid);

    printf(" %ld %s %s ", sb.st_nlink, infoUser->pw_name, infoGroup->pw_name);

    printf(" %lld ", (long long) sb.st_size);

    char strNow[ BUFFER_SIZE ];
    strftime( strNow, BUFFER_SIZE, "%a %d %R", gmtime( &sb.st_mtim.tv_sec ) );

    if(is_dir(pathfile)){
        printf(" %s %s%s%s%s%s\n", strNow, BG_GREEN,BLUE,get_basename(pathfile),BG_NORMAL,NORMAL_COLOR);
    }else{
        printf(" %s %s%s%s\n", strNow, GREEN,get_basename(pathfile),NORMAL_COLOR);
    }
}

void list(char *pathname){
    DIR* dir = opendir(pathname);
    struct dirent *d;
    if (dir) {
        printf("%s:\n", pathname);
        while ((d = readdir(dir)) != NULL) {
            char *res = joinFile(pathname,d->d_name);
            print_fileinfo(res);
            free(res);
        }
        rewinddir(dir);
        while ((d = readdir(dir)) != NULL) {
            char *res = joinFile(pathname,d->d_name);
            if(is_dir(res) && !is_dot_dir(d->d_name)){
                list(res);
            }
            free(res);
        }
        closedir(dir);
    } else if (ENOENT == errno) {
        
    } else {
        perror("interal error");
    }
}

int main(int argc, char **argv){
    if(argc==1){
        list(".");
        return 0;
    }
    for(int i=1;i<argc;i++){
        list(argv[i]);
    }
    return 0;
}