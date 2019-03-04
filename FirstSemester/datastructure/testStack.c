#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
char str[MAX][50];
int size,top=-1;


void push(char data[50]){
    if(top==size-1){
        printf("\nStack overflow\n");
        return;
    }
    else{
        top=top+1;
        strcpy(str[top],data);
        printf("String inserted is %s ",data);
    }
}

void pop(char data[50]){
    if(top==-1){
        printf("\nStack underflow");
        return;
    }
    else{
        strcpy(data,str[top]);
        printf("\nElement deleted is %s ",data);
        top=top-1;
    }
}

void peek(){
    if (top == -1)
        printf("\nStack is underflow\n");
        else
    printf("Top string element is %s ",str[top]);
}

void display(){
    if (top == -1)
        printf("\nStack is underflow\n");
        else{
            printf("Elements are : \n");
            for(int i=top;i>=0;i--){
                printf(" %s \n",str[i]);
            }
        }
}

void main(){
    char data[50];
    int ch;
    printf("\nEnter size of stack\n");
    scanf("%d",&size);
    while(1){
        printf("\n1-push\n2-pop\n3-peek\n4-display");
        printf("\nEnter choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter string in stack\n");
                scanf("%s",&data);
                push(data);
                break;
            case 2:
                pop(data);
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
    }
    
}