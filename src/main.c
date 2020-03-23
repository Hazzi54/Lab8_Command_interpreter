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

        char c, *str_result;
        int i = 0;
        str_result = (char *)malloc(sizeof(char));
        while(read(fd2[0], &c, sizeof(char))) {
            str_result[i] = c;
            i++;
            str_result = (char *)realloc(str_result, (i + 1) * sizeof(char));
        }
        close(fd2[0]);
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
                i = 1;
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
                
                char *str_tmp, c;
                int i = 0;
                str_tmp = (char *)malloc(sizeof(char));
                while(read(fd1[0], &c, sizeof(char))) {
                    str_tmp[i] = c;
                    i++;
                    str_tmp = (char *)realloc(str_tmp, (i + 1) * sizeof(char));
                }

                close(fd1[0]);
                puts(str_tmp);
                mas = parsing_func(str_tmp);
                free(str_tmp);
                execvp(mas[0], mas);
            }
        }
    }
    else {
        close(fd1[1]);
        close(fd2[0]);
        dup2(fd2[1], 1);

        char *str_tmp, c;
        int i = 0;
        str_tmp = (char *)malloc(sizeof(char));
        while(read(fd1[0], &c, sizeof(char))) {
            str_tmp[i] = c;
            i++;
            str_tmp = (char *)realloc(str_tmp, (i + 1) * sizeof(char));
        }
        close(fd1[0]);
        puts(str_tmp);
        mas = parsing_func(str_tmp);
        free(str_tmp);
        execvp(mas[0], mas);
    }
    return 0;
}
