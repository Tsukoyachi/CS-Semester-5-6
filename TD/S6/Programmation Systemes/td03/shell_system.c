#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2048
#endif

char *readShell(char *saveHere);
void prompt();
void executeCommand(char *command);

int main(){
    char line[BUFFER_SIZE];

    prompt();

    while(readShell(line)) {
        if(line[0] == '\n'){
            prompt();
            continue;
        }

        char line2[BUFFER_SIZE];
        strcpy(line2,line);

        if(strcmp("\0",line2) == 0){
            break;
        }

        executeCommand(line);
        prompt();
    }

    return 0;
}

char *readShell(char *saveHere){
    if(fgets(saveHere,BUFFER_SIZE,stdin) == NULL){
        return NULL;
    }
    
    char *backslashN = strchr(saveHere,'\n');
    if(backslashN != NULL){
        *backslashN ='\0';
    }

    return saveHere;

}

void prompt() {
    printf("$ ");
    fflush(stdout);
}

void executeCommand(char *command){
    char cmdCopy[BUFFER_SIZE];
    strcpy(cmdCopy,command);
    char *cmd;

    cmd = strtok(cmdCopy," ");
    if(strcmp("cd",cmd) == 0 ){
        char *dir = strtok(NULL," ");
        if(dir == NULL){
            chdir(getenv("HOME"));
        }
        if(chdir(dir) < 0){
            perror("chdir");
        }
        return;
    }
        
    system(command);
}



int main() {
    char buffer[1024];
    printf("prompt : \n");
    while(fgets(buffer,1024,stdin) != 0){
        system(buffer);
        printf("\nprompt :\n");
    }
    return 0;
}