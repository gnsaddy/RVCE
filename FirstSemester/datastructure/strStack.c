#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 10
char stack[max][80];
int top = -1,size;

int push(char data[80])
{
    if (top == size - 1)
        printf("\nStack is full\n");
    else
    {   
        top = top + 1;
        strcpy(stack[top], data);
        printf("\nPushed String is : %s\n",data);
    }
}
int pop(char data[80])
{
    if (top == -1)
        printf("\nStack is underflow\n");
    else
    {
        strcpy(data, stack[top]);
        printf("\nPopped string is : %s\n", data);
        top = top - 1;
        return (1);
    }
}

void peek(){
    if (top == -1)
        printf("\nStack is underflow\n");
    else {
        printf("\nPeek string is : %s  \n",stack[top]);
    }
}

void display(){
    if (top == -1)
        printf("\nStack is underflow\n");
    printf("\nStack element are : \n");
    for(int i=top;i>=0;i--)
    {
        printf("%s\n",stack[i]);
    }
}
int main()
{
    char nm[80];
    int ch;
    printf("\nEnter the size of stack\n");
    scanf("%d",&size);
     // Initialize Stack
    
    while (1)
    {
        printf("\tMENU");
        printf("\n----------------------------\n");
        printf("      1. PUSH\n");
        printf("      2. POP\n");
        printf("      3. PEEK\n");
        printf("      4. DISPLAY\n");
        printf("      5. EXIT\n");
        printf("----------------------------\n");
        printf("\nChoose operation : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // push
            printf("\nEnter string : ");
            scanf("%s", nm);
            push(nm);           
            break;
        case 2: // pop
            pop(nm);
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid operation \n");
        }
    }
    return 0;
}