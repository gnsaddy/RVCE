#include<stdio.h>
#include<stdlib.h>

int size,mutex=1,full=0,empty,x=0;
void producer();
void consumer();
int wait(int);
int signal(int);

int main(){
	int ch;
	printf("\nEnter the buffer size :");
	scanf("%d",&size);
	empty=size;
	printf("\n1-Producer\n2-Consumer\n");
	while(1){
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				if((mutex==1) && (empty!=0))
					producer();
				else
					printf("\nBuffer is full\n");
				break;
			case 2:
				if((mutex==1) && (full!=0))
					consumer();
				else
					printf("\nBuffer is empty\n");
				break;
			}
		}
	return 0;
}

int wait(int s){
	return --s;
}

int signal(int s){
	return ++s;
}

void producer(){
	mutex = wait(mutex);
	full = signal(full);
	empty = wait(empty);
	x++;
	printf("\nProducer produces item %d",x);
	mutex = signal(mutex);
}

void consumer(){
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);
	printf("\nConsumer consumes item %d ",x);
	x--;
	mutex = signal(mutex);
}

