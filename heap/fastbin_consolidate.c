#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
    void *p = malloc(0x30);
    void *p4 = malloc(0x30);
    free(p);
    void *p1 = malloc(0x400);
    free(p);
    void *p2 = malloc(0x30);
    void *p3 = malloc(0x30);
    printf("p2 : %p\n",p2);
    printf("p3 : %p\n",p3);
    return 0;
}