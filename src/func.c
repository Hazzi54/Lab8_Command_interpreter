#include "func.h"

int check(char *str) {
    int i = 0, l = strlen(str);
    while(i < l) {
        if(str[i] == '|') {
            if(i != 0)
                if(str[i-1] == ' ')
                    return i-1;
            else
                return i;
        }
        i++;
    }
    return -1;
}

char *read_string_func() {
    char *buf = NULL;        // here
    getline(&buf, 0, stdin);
    return buf;
}

#define TOK_DEL " \t\n"

char **parsing_func(char *str) {
    int size = 32, i = 0, l = strlen(str);
    char **mas = malloc(size * sizeof(char *));
    char *token, str_tmp[l];
    strcpy(str_tmp, str);
    
    if(!mas) {
        fprintf(stderr, "Memory allocation err\n");
        exit(EXIT_FAILURE);
    }
    
    puts(str);
    puts(str_tmp);
    token = strtok(str_tmp, TOK_DEL);
    puts(token);
    while(token != NULL) {   //here
        mas[i] = token;
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
    puts(mas[0]);
    puts(mas[1]);
    puts(mas[2]);
    return mas;
}

















