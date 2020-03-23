#include "func.h"

// fd[0] - read; fd[1] - write

int main(int argc, char *argv[]) {
    char command[50], buf[50];
    fgets(command, 50, stdin);
    fflush(stdin);
    int var = check(command);
    int fd1[2], fd2[2], i;
    //pid_t pid1, pid2;
    pipe(fd);
    if(fork()) {       // parent
        close(fd1[0]);
        if(var < 0)
            write(fd1[1], command, strlen(command) + 1);
        else
            write(fd1[1], command, var + 1);
        close(fd1[1]);
        wait(NULL);

    }
    else {             // child 1
        //dup2(fd1[1], 1);
        close(fd1[1]);
        read(fd1[0], buf, sizeof(buf));
        close(fd1[0]);
        buf[strlen(buf) - 1] = '\0';
        execvp(buf, argv);
    }  
    return 0;
}
