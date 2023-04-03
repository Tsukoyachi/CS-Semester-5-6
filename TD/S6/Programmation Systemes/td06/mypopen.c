int main(int argc, char *argv[]) {

    if(argc < 2){
        printf("You forget to put a command in parameter...\n");
        exit(1);
    }
    int pipes[2];
    if(pipe(pipes) == -1){
        printf("An error occured with the pipe...\n");
        exit(1);
    }

    int tmpStandardFd;
    dup(1,tmpStandardFd);

    switch(fork()) {
        case -1 : {
            printf("An error occured with the fork...\n");
            exit(1);
        }
        case 0 : {
            dup2(pipes[1],1);
            execl("/bin/sh", "sh", "-c", &(argv[1]), (char *) NULL);
            exit(1);
        }
        default : {
            wait(0);
        }
    }

    

    return 0;
}