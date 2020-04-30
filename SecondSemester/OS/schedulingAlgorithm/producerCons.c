#include<stdio.h>
#include<stdlib.h>
 
int mutex=1,full=0,empty,x=0;
	void producer();
	void consumer();
	int wait(int);
	int signal(int);
 
int main()
{
	int size;
	printf("\nEnter size of buffer : ");
	scanf("%d",&size);
	empty=size;
    if(size<=0)
    {
    	printf("\nEnter valid buffer size!");
    	exit(0);
	}
	
	while(1)
	{
		int ch;
		printf("\n1.Producer\n2.Consumer\n3.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	if((mutex==1) && (empty!=0))
						producer();
					else
						printf("\nBuffer is full!!");
					break;
			case 2:	if((mutex==1) && (full!=0))
						consumer();
					else
						printf("\nBuffer is empty!!");
					break;
			case 3:
					exit(0);
			default:printf("Invalid choice!");  
					break;
		}
	}
	
	return 0;
}
 
int wait(int s)
{
	return (--s);
}
 
int signal(int s)
{
	return (++s);
}
 
void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("\nProducer produces the item %d",x);
	mutex=signal(mutex);
}
void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("\nConsumer consumes item %d",x);
	x--;
	mutex=signal(mutex);
}