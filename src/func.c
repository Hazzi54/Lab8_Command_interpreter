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

















