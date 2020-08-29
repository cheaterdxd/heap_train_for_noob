#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *tree[3];
struct house
{
    char messageBox[16];
    char address[160];
    char key[24];
};
void init()
{
    setbuf(stdin,0);
    setbuf(stdout,0);
    setbuf(stderr,0);
}
void hello()
{
    puts("Hello ,welcome to the heap with cheaterdxd !");
    puts("But today, he is sick and he need some help with his garden.");
    puts("I think we should help and give hime the cake named 'fake fastbin chunk' as a present, he will like it");
}
void menu()
{
    // puts("1. write some message to cheaterdxd.");
    puts("1. Help him free tree.");
    puts("2. Help him plan tree.");
    puts("3. Get the flag.");
    puts("4. Exit.");
    puts("Your choice: ");
}
void planTree()
{
    for(int i=0;i<3;i++)
    {
        if(tree[i]==0){
            int len = 0;
            puts("Input len of tree: ");
            scanf("%d",&len);
            getchar();
            tree[i] = malloc(len);
            *tree[i] = 1;
            printf("Write your name on tree for gift: ");
            fgets(tree[i],len,stdin);
            puts("Thank you so much");
            break;
        }
    }
}
void freeTree()
{

    for(int i=0;i<3;i++)
    {
        printf("The %d tree is at %p and tall %d m \n",i+1,tree[i],0x20);
    }
    while(1)
    {
        puts("Choose the tree you want to free by input tree's address: ");
        char *address = malloc(0x10);
        fgets(address,10,stdin);
        for(int i=0;i<3;i++)
        {
            if(strcmp(address,&tree[i])) tree[i]=0;
        }
        if(!strcmp(address,"exit")) break;
        int **temp = (int *) address;
        if( **temp ==NULL)
        {
            puts("Not free more than one !");
            continue;
        }
        free(*temp);
        puts("Done !");
    }
    // puts("Good job ! Now he want you malloc some new tree before give him the cake ! Do you want to help him or steal his flag without help?");
}
void getFlag(struct house cheaterdxdHouse)
{
    if(!strcmp(cheaterdxdHouse.key,"hacked!")) puts("CTF{You_are_kind_So_this_is_your_flag");
}
void help(struct house cheaterdxdHouse)
{
    puts("Oh his garden has 3 trees, you need do something with all of them!");
    
    tree[0] = malloc(0x20); 
    tree[1] = malloc(0x20);
    tree[2] = malloc(0x20);
    *tree[0] = 1;
    *tree[1] = 1;
    *tree[2] = 1;
    while(1)
    {
        menu();
        int choice;
        scanf("%d",&choice);
        getchar();
        if(choice == 1)
        {
            freeTree();
        }
        if(choice == 2) planTree();
        if(choice == 3) getFlag(cheaterdxdHouse);
        if(choice == 4)
        {
            printf("Good bye!\n");
            exit(0);
        }
    }
    
}
int main()
{
    init();
    hello();
    puts("yes or no (y/n) ?");
    char choice;
    choice = getchar();
    getchar();
    if(choice=='y')
    {
        struct house cheaterdxdHouse; 
        // printf("Cheaterdxd address is %p\n",cheaterdxdHouse);
        printf("Cheaterdxd's message address is at %p\n",cheaterdxdHouse.messageBox);
        printf("Cheaterdxd address is %p\n",cheaterdxdHouse.address);
        printf("Cheaterdxd address is %p\n",cheaterdxdHouse.key);
        puts("You can write a message to house !");
        fgets(cheaterdxdHouse.messageBox,100,stdin);
        puts("Content: ");
        puts(cheaterdxdHouse.messageBox);
        help(cheaterdxdHouse);
    }
    else
    {
        puts("CTF{no_you_are_not_good_to_get_flag}");
        return 0;
    }
    
    
    
    

    return 0;
}