#include "func.h"

// fd[0] - read; fd[1] - write

int main(int argc, char *argv[]) {
    char command[50], buf[50];
    fgets(command, 50, stdin);
    fflush(stdin);
    int var = check(command);
    int fd[2], i;
    pid_t pid;
    pipe(fd);
    if(fork()) {       // parent
        close(fd[0]);
        write(fd[1], command, strlen(command) + 1);
        close(fd[1]);
        wait(NULL);
    }
    else {             // child
        //dup2(fd[1], 1);
        close(fd[1]);
        read(fd[0], buf, sizeof(buf));
        close(fd[0]);
        buf[strlen(buf) - 1] = '\0';
        execvp(buf, argv);
    }  
    return 0;
}
