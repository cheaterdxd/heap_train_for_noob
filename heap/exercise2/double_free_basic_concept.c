#include<stdio.h>
#include<stdlib.h>
char *pages[3]={0};
int inuse[3]={0};
void init()
{
    setbuf(stdin,0);
    setbuf(stdout,0);
    setbuf(stderr,0);
}
int getPage()
{
    puts("Please choose the page u want:");
    int page = 0;
    scanf("%d",&page);
    getchar();
    if(page>3 || page<1)
    {
        puts("Don't do this"); 
        exit(0); 
    }
    return page;
}
void mallocPage()
{
    int index = getPage();
    inuse[index-1] = 1;
//     if(pages[index-1])
//     {
//         printf("Oh-no, this page has been allocated");
//         return;
//     }
    pages[index-1] = malloc(0x20);
    printf("Input the content of page.\n");
    printf("Becareful ! The length of content only <= 0x19 characters.\n");
    puts(">>>");
    fgets(pages[index-1],0x19,stdin);
    printf("Malloc success!\n");
}
void deletePage()
{
    int index = getPage();
    free(pages[index-1]);
    inuse[index-1] = 0;
    printf("Page has been deleted!\n");
}
void checkToGetFlag()
{
    if(pages[0]==pages[2] && pages[0]!=0)
    {
        printf("That's right. CTF{You_are_good_but_not_enough}\n");
        if(inuse[0]==1 && inuse[2]==1) puts("CTF{Double_free_is_f*cking_easy}");
    }
    else
    {
        printf("Not yet. Try again\n");
    }
}
void menu()
{
    puts("\n1. Malloc page.\n2. Delete page.\n3. Check to get Flag.\n4. Exit.\nYour choice: ");
}

    
int main()
{
    init();
    printf("Hello, i give u only 3 (1,2,3) pages, but it can help you to get the secret.\n");
    printf("May be you need to do something twice in life.\n");
    while(1)
    {
        menu();
        int choice;
        scanf("%d",&choice);
        getchar();
        if(choice == 1)
        {
            mallocPage();
        }
        if(choice == 2) deletePage();
        if(choice == 3) checkToGetFlag();
        if(choice == 4)
        {
            printf("Good bye!\n");
            exit(0);
        }
    }
}
