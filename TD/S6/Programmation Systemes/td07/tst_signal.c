#include <signal.h>
#include <unistd.h>

int main() {
    signal(SIGSEGV,SIG_IGN);
    signal(SIGINT,SIG_IGN);
    sleep(20);
}