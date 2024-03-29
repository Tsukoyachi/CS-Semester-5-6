#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if(argc < 2){
        printf("You didn't provide the name of the named pipe, please retry...\n");
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY, 0777);
    char c;
    while(read(fd,&c,1) > 0) {
        printf("%c",c);
    }

    return 0;
}