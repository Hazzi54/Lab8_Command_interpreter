#include "func.h"

// fd[0] - read; fd[1] - write

int main() {
    char *line;
    char **mas;
    line = read_string_func();
    puts("Here main");
    mas = parsing_func("ls -la -qw");
    return 0;
}
