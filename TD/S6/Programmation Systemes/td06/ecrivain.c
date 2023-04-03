#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc < 2){
        printf("You didn't provide the name of the named pipe, please retry...\n");
        exit(1);
    }
    if(mkfifo(argv[1],0777) == -1){
        printf("An error occured with the named pipe...\n");
        exit(1);
    }

    int fd = open(argv[1], O_WRONLY, 0777);
    int written_char = write(fd,"test...",7*sizeof(char));
    if(written_char<= 0) {
        printf("An error occured with the writing...\n");
        exit(1);
    }

    return 0;
}