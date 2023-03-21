#include "util.h"


void cpInFile(char *fileStart, char *fileDest) {

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