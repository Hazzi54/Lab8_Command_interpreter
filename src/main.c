#include "func.h"

// fd[0] - read; fd[1] - write

int main() {
    char *line;
    char **mas;
    line = read_string_func();
    mas = parsing_func(line);
    return 0;
}
