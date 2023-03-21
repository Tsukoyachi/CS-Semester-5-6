#include "util.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



void cpInFile(char *fileStart, char *fileDest) {
    if(!file_exists(fileStart)){
        printf("Start file doesn't exist...");
        exit(1);
    }
    open(fileStart,O_RDONLY);
    open(fileDest, O_CREAT, O_WRONLY);
}

void cpFileInDirectory(int argc, char *files[]){

}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        return 0;
    }
    if (argc == 3) {
        cpInFile(argv[1], argv[2]);
    }
    if (argc > 3){
        cpFileInDirectory(argc, &argv);
    }

    return 0;
}