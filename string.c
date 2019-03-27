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

char* stradd(char* str1, char* str2){
    char * new_str ;
    if((new_str = malloc(strlen(str1)+strlen(str2)+1)) != NULL){
    new_str[0] = '\0';   // ensures the memory is an empty string
    strcat(new_str,str1);
    strcat(new_str,str2);
    }
    return new_str;
}

int howmany_int(int argv){
    int i;
    for(i = 0; argv != 0; i++){
        argv /= 10;
    }
    return i;
}

char *my_itoa(int num){
    char* str;
    if((str = (char*)malloc((howmany_int(num) + 1) * sizeof(char))) != NULL){
        sprintf(str, "%d", num);
        return str;
    }
    else return NULL;

}

char** cut_string(char *str, char *sep, int* length){
    char* newstr;
    char* newsep;
    char** result;
    int i = 0, j = 0;
    int pre = 0;
    if((newstr = (char*)malloc((strlen(str) + 1) * sizeof(char))) != NULL 
    && (newsep = (char*)malloc((strlen(sep) + 1) * sizeof(char))) != NULL){
        strcpy(newstr, str);
        strcpy(newsep, sep);
        char* token; 
        char* rest = newstr; 
        result = (char**)malloc(sizeof(char*));
        while ((token = strtok_r(rest, newsep, &rest))) {
            // printf("%s\n", token); 
            result = (char**)realloc(result, (i + 1) * sizeof(char*));
            *(result+i) = (char*)malloc((strlen(token) + 1) * sizeof(char));
            strcpy(*(result+i), token);
            i++;
        }
        free(newstr);
        free(newsep);
    }
    *length = i;//Store the 1-dimensional length.
    return result;
}

int main(int argc, char** argv){
    
    // char* input;
    // int inpid = 0;
    // input = (char*)malloc(10 * sizeof(char));
    // scanf("%s", input);
    // divide(input, &inpid);
    // printf("string is [%s]\nint is [%d]\n", input, inpid);


    // printf("[%d]\n", howmany_int(100));


    int length;
    char** result = cut_string("asdas/dasdas/dasdaqweq/wedsa", "/", &length);
    for(int i = 0; i < length; i++){
        // sz -= sizeof(*(result+i))/sizeof(char);
        printf("%s\n", *(result+i));
        // if(sz == 0) break;
    }
   
   
    return EXIT_SUCCESS;
}
