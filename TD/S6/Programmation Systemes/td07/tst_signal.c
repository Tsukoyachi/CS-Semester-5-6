#include <signal.h>

int main() {
    signal(SIGSEGV,SIG_IGN);
    signal(SIGINT,SIG_IGN);
}