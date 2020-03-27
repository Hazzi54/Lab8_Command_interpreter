#include "func.h"

// fd[0] - read; fd[1] - write

int main(int argc, char *argv[]) {
    char *line, **mas;
    line = read_string_func();
    int fd1[2], fd2[2], length = strlen(line);
    pipe(fd1);
    pipe(fd2);

    if(fork()) {
        close(fd1[0]);
        close(fd2[1]);
        int ch = check(line);
        char *buf1, *buf2;
        if(ch != -1) {
            buf1 = strtok(line, "|");
            buf2 = strtok(NULL, "|");
            write(fd1[1], buf1, strlen(buf1) - 1);
        }
        else
            write(fd1[1], line, length);
        close(fd1[1]);
        
        char *str_result = read_from_pipe(fd2[0]);
        wait(NULL);
        if(ch < 0) {
            puts(str_result);
        }
        else {
            pipe(fd1);
            pipe(fd2);
            if(fork()) {  // parent
                close(fd1[0]);
                close(fd2[0]);
                int i = 1;
                while(i < strlen(buf2)) {
                    write(fd1[1], &buf2[i], 1);
                    i++;
                }
                close(fd1[1]);
                write(fd2[1], str_result, strlen(str_result));
                close(fd2[1]);
                wait(NULL);
            }
            else {        //child
                close(fd1[1]);
                close(fd2[1]);
                dup2(fd2[0], 0);
                
                launch_new_proc(fd1, fd2);
            }
        }
    }
    else {
        close(fd1[1]);
        close(fd2[0]);
        dup2(fd2[1], 1);

        launch_new_proc(fd1, fd2);
    }
    return EXIT_SUCCESS;
}
