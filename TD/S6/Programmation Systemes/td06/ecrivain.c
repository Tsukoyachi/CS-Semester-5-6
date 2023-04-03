#include <fcntl.h>
#include <stdio.h>
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

    return 0;
}