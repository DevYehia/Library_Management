#include "utility.h"


void safeInput(s8 inp [] , u32 maxLimit){
    char c;
    u32 i;
    for(i = 0 ; i < maxLimit ; i++){
        c = getchar();
        if(c == '\n')
            break;
        inp[i] = c;
    }
    inp[i] = '\0';
}

void red(){
    printf("\033[0;31m");
}

void yellow(){
    printf("\033[0;33m");
}

void green(){
    printf("\033[0;32m");
}


void blue(){
    printf("\033[0;34m");
}

void white(){
    printf("\033[0;37m");
}

void magenta(){
    printf("\033[0;95m");
}
