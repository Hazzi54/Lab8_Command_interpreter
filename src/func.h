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
void launch_proc_func(char **);

#endif
