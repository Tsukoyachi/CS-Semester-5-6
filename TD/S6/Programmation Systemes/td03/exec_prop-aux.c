#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    //The caller buffer isn't printed there, so it'snt shared between them
    fflush(stdout);
    //The proof that we can print something
    printf("%d, %s\n",getpid(),*(++argv));
    return 0;
}