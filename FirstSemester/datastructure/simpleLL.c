#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

 struct node {
  int data;
  struct node* next;
};

struct node* head=NULL;
int count=0;

void addBeg(int val){
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  count++;

  temp->data = val;
  temp->next = head;
  head = temp;
  printf("\nvalue inserted %d ",val );
}

void addEnd(int val){
  struct node *t, *temp;
  t = (struct node*)malloc(sizeof(struct node));
  count++;
  if(head == NULL){
    head = t;
    head->data=val;
    head->next=NULL;
    return;
  }
  temp=head;

  while(temp->next!=NULL){
    temp=temp->next;
  }

    temp->next=t;
    t->data=val;
    t->next=NULL;

}

void display(){
  struct node *temp;

   temp= head;

   if (temp == NULL) {
      printf("Linked list is empty.\n");
      return;
   }
   else{

   printf("There are %d elements in linked list.\n", count);

   while (temp!= NULL) {
      printf("%d\n", temp->data);
      temp= temp->next;
   }
 }
   printf("%d\n", temp->data);
}

 void delBeg(){
   struct node *temp;
   int n;
   temp=head;
   if(head==NULL){
     printf("Empty list\n");
   }
   else{
   n=head->data;
   temp=head->next;
 }
   free(temp);
   // head=temp;
   // count--;
   printf("%d deleted from beginning successfully \n",n);
 }


 void delEnd() {
   struct node *t, *u;
    int n;

    if (head == NULL) {
       printf("Linked list is already empty.\n");
       return;
    }

    count--;

    if (head->next == NULL) {
       n = head->data;
       free(head);
       head = NULL;
       printf("%d deleted from end successfully.\n", n);
       return;
    }

    t = head;

    while (t->next != NULL) {
       u = t;
       t = t->next;
    }

    n = t->data;
    u->next = NULL;
    free(t);

    printf("%d deleted from end successfully.\n", n);
 }


 void insAtPos(int data, int position){
   struct node *ptr = (struct node*)malloc(sizeof(struct node));
    	//Creating a new node
    	ptr->data=data;

    	int i;
    	struct node *temp=head;
    	//Do not use the pointer variable head directly. If we use it, the address location of the first node in the linked list will be lost
    	//Pointer variable temp is used to traverse the linked list

    	if(position==1)
    {
        //Executed only if position is 1
        		//If position is 1, it is a special case because we need to modify the head  pointer
        		ptr->next=temp;
        		//ptr->next=head is also valid;

        		head=ptr;
        		//Making head point to newly created node ptr
        		return;
    	}

    	//Function to insert node at position n in the linked list
    	//If we have  5nodes in the linked list, we can insert a new a node between any two nodes of the five nodes present in the linked list

    	for(i=1;i<position-1;i++)//Traversing to the (n-1)th position node in the linked list
    	{
        		temp=temp->next;
    	}

    	ptr->next=temp->next;
    	//Making the newly created node point to next node of pointer temp

    	temp->next=ptr;
    	//Making pointer temp point to newly created node in the linked list
 }


void main(){
  int input, data;
  int pos;


  while(1){
      printf("1. Insert an element at beginning of linked list.\n");
      printf("2. Insert an element at end of linked list.\n");
      printf("3. Display linked list.\n");
      printf("4. Delete element from beginning.\n");
      printf("5. Delete element from end.\n");
      printf("6- At position\n");
      printf("7. Exit\n");
      printf("Enter choice\n");

      scanf("%d", &input);
    switch (input) {
      case 1:
      printf("\nEnter value of element\n");
      scanf("%d", &data);
      addBeg(data);
      break;
      case 2:
      printf("\nEnter value of element\n");
      scanf("%d", &data);
      addEnd(data);
      break;
      case 3:
      display();
      break;
      case 4:
      delBeg();
      break;
      case 5:
      delEnd();
      break;
      case 6:
      printf("Enter value \n ");
      scanf("%d",&data);
      printf("Enter data\n");
      scanf("%d",&pos);
      insAtPos(data,pos);
      break;
      default:
      printf("\nInvalid choice\n");
}
}
}
