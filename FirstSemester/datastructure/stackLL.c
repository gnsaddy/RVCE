// C program to Implement a stack
//using singly linked list
#include <stdio.h>
#include <stdlib.h>

// Declare linked list node

struct Node {
    int data;
    struct Node* link;
};
struct Node* top;
void push(int data)
{
    // create new node temp and allocate memory
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    // check if stack (heap) is full. Then inserting an element would
    // lead to stack overflow
    if (!temp) {
        printf("\nHeap Overflow");
        exit(1);
    }

    // initialize data into temp data field
    temp->data = data;

    // put top pointer reference into temp link
    temp->link = top;

    // make temp as top of Stack
    top = temp;
}

// Utility function to check if the stack is empty or not

// Utility function to return top element in a stack
int peek()
{
    // check for empty stack
    if (top!=NULL)
        printf("Top element is %d\n",top->data );
}

// Utility function to pop top element from the stack

void pop()
{
    struct Node* temp;
    int n;

    // check for stack underflow
    if (top == NULL) {
        printf("\nStack Underflow");
        exit(1);
    }
    else {
        n=top->data;
        // top assign into temp
        temp = top;

        // assign second node to top
        top = top->link;

        // destroy connection between first and second
        temp->link = NULL;

        // release memory of top node
        free(temp);
    }
    printf("poped element is %d\n",n );
}

void display() // remove at the beginning
{
    struct Node* temp;

    // check for stack underflow
    if (top == NULL) {
        printf("\nStack Underflow");
        exit(1);
    }
    else {
        temp = top;
        while (temp != NULL) {

            // print node data
            printf("%d->", temp->data);

            // assign temp link to temp
            temp = temp->link;
        }
    }
}

// main function

void main()
{

    int ch,val;
    while(1){
        printf("\n1-Push \n2-Pop \n3-Peek \n4-Display \n5-Exit\n");
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
            printf("Enter value to push\n");
            scanf("%d",&val);
            push(val);
            break;

            case 2:
            pop();
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
            printf("Invalid\n");
            break;
        }
    }

}
