#include<stdio.h>
int main(){
    char * ch = malloc(20);
    free(ch);
    fgets(ch,10,stdin);
    return 0;
}
