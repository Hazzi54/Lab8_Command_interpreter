#ifndef _FUNC
#define _FUNC

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int check(char *);
char *read_string_func();
char **parsing_func(char *);
char *read_from_pipe(int);
void launch_new_proc(int *, int *);

#endif
