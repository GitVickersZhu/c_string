#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void delete_current(char* str, int cur){
    do{
        if(*(str + cur + 1) == '\0') *(str + cur) ='\0';
        *(str + cur) = *(str + cur + 1);
    } while(*(str + ++cur) != '\0');
}

void divide(char* str, int* inpid){
    int i = 0;
    do {
    if(*(str+i) <= '9' && *(str+i) >= '0'){
        *inpid = *inpid * 10 + (int)(*(str + i) - '0');
        delete_current(str, i);
        --i;//it is important!
    }
    
    } while(*(str + ++i) != '\0');
}

int main(int argc, char** argv){
    
    char* input;
    int i = 0;
    int inpid = 0;
    input = (char*)malloc(10 * sizeof(char));
    scanf("%s", input);
    divide(input, &inpid);
    printf("string is [%s]\nint is [%d]\n", input, inpid);

    return 0;
}

