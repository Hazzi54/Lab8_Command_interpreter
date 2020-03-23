#include "func.h"

int check(char *str) {
    int i = 0, l = strlen(str);
    while(i < l) {
        if(str[i] == '|') {
            return i;
        }
        i++;
    }
    return -1;
}

char *read_string_func() {
    int size = 256, i = 0;
    char *buf = malloc(sizeof(char) * size);
    if(!buf) {
        fprintf(stderr, "Memory allocation err\n");
        exit(EXIT_FAILURE);
    }
    int symbol;
    
    while(1) {
        symbol = getchar();
        if((symbol == EOF) || (symbol == '\n')) {
            buf[i] = '\0';
            return buf;
        }
        else {
            buf[i] = symbol;
        }
        i++;
        
        if(i >= size) {
            size += 32;
            buf = realloc(buf, sizeof(char) * size);
            if(!buf) {
                fprintf(stderr, "Memory allocation err\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

#define TOK_DEL " \t\n"

char **parsing_func(char *str) {
    int size = 32, i = 0, l = strlen(str);
    char **mas = (char**)malloc(size * sizeof(char *));
    char *token, str_tmp[l];
    strcpy(str_tmp, str);
    
    if(!mas) {
        fprintf(stderr, "Memory allocation err\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(str_tmp, TOK_DEL);
    while(token != NULL) {
        mas[i] = (char *)malloc(strlen(token) * sizeof(char));
        strcpy(mas[i], token);
        i++;
        
        if(i >= size) {
            size += 32;
            mas = realloc(mas, size * sizeof(char *));
            
            if(!mas) {
                fprintf(stderr, "Memory allocation err\n");
                exit(EXIT_FAILURE);
            }
        }
        
        token = strtok(NULL, TOK_DEL);
    }
    mas[i] = NULL;
    return mas;
}
















