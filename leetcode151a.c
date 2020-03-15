#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char * reverseWords(char * s){
    if (s == NULL)
        return "" ;
    
    while(*s == ' '){
        s++;
    }
    if(strlen(s) == 0)
        return "" ;
    char *end = s + strlen(s) - 1;
    while(*end == ' ' && s <= end)
        end--;
    *(end + 1) = '\0';

    char *new = (char *) malloc (sizeof(char) *(strlen(s) + 1));
    int currentwordLen = 0;
    int wordLen = 0;
    char *ptr;
    printf("start:%s:end\n", s);
    for (ptr = end; ptr >= s; ptr--){
        while( *ptr != ' ' && ptr > s){
            currentwordLen++;
            ptr--;
        }
        if(ptr == s){
            strncpy(new + wordLen,ptr, currentwordLen + 1);
            wordLen += currentwordLen;
            *(new + wordLen + 1) = '\0';
            return new;
        }else if (currentwordLen > 0){
            strncpy(new + wordLen,ptr+1, currentwordLen);
            wordLen += currentwordLen;
            *(new + wordLen) = ' ';
            wordLen++;
            currentwordLen = 0;
        }

    }
    return new;
}
int main(){
    char s[] = "a good   example";

    char *ptr = s;
    printf("start:%s:end\n", ptr);
    ptr = reverseWords(ptr);
    printf("start:%s:end\n", ptr);
    return 0;
}