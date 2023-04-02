#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main() {
    int fd = open("foo", O_TRUNC | O_CREAT | O_WRONLY, 0777);
    dup2(fd,1);
    close(fd);
    execlp("/bin/ls","ls","-l",NULL);
}