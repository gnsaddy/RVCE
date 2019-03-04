#include <stdio.h>

#define SIZE 10

int items[SIZE];
int front = -1, rear =-1;
int lim;

void enQueue(int element)
{
    if ( (front == rear + 1) || (front == 0 && rear == lim-1))
     printf("\n Queue is full!! \n");
    else
    {
        if(front == -1) front = 0;
        rear = (rear + 1) % lim;
        items[rear] = element;
        printf("\n Inserted -> %d \n", element);
    }
}

int deQueue()
{
    int element;
    if(front == -1) {
        printf("\n Queue is empty !! \n");
    } else {
        printf("%d deleted ", items[front]);
        if (front == rear){
            
            front = -1;
            rear = -1;
        } /* Q has only one element, so we reset the queue after dequeing it. ? */
        else {
           
           front = (front + 1) % lim;

        }
        
    }
}

void display()
{
    int i;
    if(front == -1)
     printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d \n",front);
        printf("\n Items -> \n ");
        for( i = front; i!=rear; i=(i+1)%lim) {
            printf("%d ",items[i]);
        }
        printf("%d ",items[i]);
        printf("\n Rear -> %d \n",rear);
    }
}

void main()
{
    int ch,i,item;

    printf("\n Enter the limit \n");
    scanf("%d",&lim);

    while(1){
        printf("\n1-Insert \n2-Delete \n3-Display \n4-Exit");
        printf("\nEnter Choice \n");
        scanf("%d",&ch);

        switch (ch) {
            case 1:
            printf("\nEnter item \n");
            scanf("%d",&item);
            enQueue(item);
            break;

            case 2:
            deQueue();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
            break;

            default:
            break;
        }
    }
}
