#include "func.h"

// fd[0] - read; fd[1] - write

int main(int argc, char *argv[]) {
    char *line;
    char **mas;
    line = read_string_func();
    puts(line);
    mas = parsing_func(line);

    if(fork()) {
        wait(NULL);
    }
    else {
        execvp(mas[0], mas);
    }

    /*int fd1[2];
    pipe(fd1);
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
    }*/
    return 0;
}
