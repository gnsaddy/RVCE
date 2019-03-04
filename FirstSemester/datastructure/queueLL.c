/*Queue - Linked List implementation*/
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
// Two glboal variables to store address of front and rear nodes.
struct Node* front = NULL;
struct Node* rear = NULL;
// To Enqueue an integer

void Enqueue(int val) {
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data =val;
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

// To Dequeue an integer.
void Dequeue() {
	struct Node* temp;
	int n;
	temp = front;
	if(front == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	if(front == rear) {
		front = rear = NULL;
	}
	else {
		n=front->data;
		front = front->next;
	}
	free(temp);
	printf("deleted element is %d\n",n);
}

int Front() {
	if(front == NULL) {
		printf("Queue is empty\n");
		return;
	}
	printf("Front data is %d",front->data);
}

void Print() {
	struct Node* temp;
	temp = front;
	while(temp!= NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void main(){
	int val,ch;
	while(1){
        printf("\n1-Inqueue \n2-Dequeue \n3-Front \n4-Display \n5-Exit\n");
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
            printf("Enter value to insert\n");
            scanf("%d",&val);
            Enqueue(val);
            break;

            case 2:
            Dequeue();
            break;

            case 3:
            Front();
            break;

            case 4:
            Print();
            break;

            case 5:
            exit(0);

            default:
            printf("Invalid\n");
            break;
					}
				}
}
