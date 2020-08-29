#include<stdio.h>
int main(){
    char *name = malloc(0x20);
    char *rootname = malloc(0x20);
    printf("Hello player, welcome to heap struct, please input your name: ");
    fgets(name,0x100,stdin);
    printf("Hello %s \n",name);
    if(!strcmp(rootname,"root"))
    {
        printf("your flag: CTF{heap_is_terrible}\n");
    }
    else
    {
        printf("Try again!\n");
    }
    free(name);
    free(rootname);
    return 0;
}
