#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void list(char *directory) {

}

int main(int argc, char *argv[]){
    for(int i = 0; i < argc; i++){
        list(argv[i]);
    }

    return 0;
}