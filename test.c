#include<stdio.h>
#include<string.h>

void main(){
    char *str = "Hello";
    char *str2 = "s";
    char temp[10];
    strcpy(temp,str);
    strcat(temp,str2);
    
    printf("%s\n",temp);
}
