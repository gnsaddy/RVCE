#include<stdio.h>
#include<stdlib.h>

int mutex=1,empty,full=0,x=0,size;
void producer();
void consumer();
int signal(int);
int wait();

int main(){
    printf("\nEnter the buffer size\n");
    scanf("%d",&size);
    empty=size;

    if(size<=0){
        printf("\nEnter valid buffer size\n");
        exit(0);
    }

    while (1)
    {
        int ch;
        printf("\n1-Producer\n2-Consumer\n3-Exit\n");
        printf("\nEnter choice\t");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            if((mutex == 1) && (empty != 0))
                producer();
            else{
                printf("\nBuffer is full\n");
            }
            break;
        
        case 2:
            if((mutex == 1) && (full != 0 ))
                consumer();
            else
            {
                printf("\nBuffer is empty\n");
            }
            break;
        
        case 3:
            exit(0);           
        
        default:
            printf("\nEnter valid choice\n");
            break;
        }       
    }   
}

int wait(int s){
    return (--s);
}

int signal(int s){
    return (++s);
}

void producer(){
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces item : %d  ",x);
    mutex = signal(mutex);
}

void consumer(){
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer conmuses item : %d ",x);
    x--;
    mutex = signal(mutex);

}