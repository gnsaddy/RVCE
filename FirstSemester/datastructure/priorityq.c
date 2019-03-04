#include<stdio.h>
#include<stdlib.h>
int size,f1=0,f2=0,f3=0;
int r1=-1,r2=-1,r3=-1;
int q1[50],q2[50],q3[50],p,v;

void insert(int);
int Delete();
void display();
int main()
{
	int ch,i,j;
	printf("Enter the size:");
	scanf("%d",&size);

	while(1)
	{
	printf("1.Insert \n2.delete \n3.display \n4.Exit\n");
	printf("Enter your choice:");
	scanf("%d",&ch);

	switch(ch)
	{
	case 1:printf("Enter priority:");
		scanf("%d",&p);
		insert(p);
		break;

	case 2:Delete();
		break;

	case 3:display();
		break;

	case 4:exit(0);
		break;

	default:printf("Wrong choice");
		break;
	}
}
}

void insert(int p)
{
	if(p==1)
	{
	if(r1==size-1)
	{
	printf("Queue 1 is full\n");
	}
	else
	{
	printf("Enter the value:");
	scanf("%d",&v);
		r1++;
		q1[r1]=v;
	}
	}
	else if(p==2)
	{
        if(r2==size-1)
        {
	 printf("Queue 2 is full\n");
        }
	else
        {
        printf("Enter the value:");
        scanf("%d",&v);
                r2++;
                q2[r2]=v;
        }
        }

        else if(p==3)
	{
        if(r3==size-1)
        {
	 printf("Queue 3 is full\n");
        }
	else
        {
        printf("Enter the value:");
        scanf("%d",&v);
                r3++;
                q3[r3]=v;
        }
        }

        else
	{
	printf("Wrong priority\n");
	}
}

int Delete()
{
	if(r1==-1 ||f1>r1)
	{
	printf("Queue 1 is empty\n");
	//f1=0,r1=-1;
	}
	else
	{
	printf("Deleted element is: %d\n",q1[f1++]);
	return 1;
	}

	 if(r2==-1 ||f2>r2)
        {
        printf("Queue 2 is empty\n");
       // f2=0,r2=-1;
        }
        else
        {
        printf("Deleted element is: %d\n",q2[f2++]);
        return 1;
        }

	 if(r3==-1 ||f3>r3)
        {
        printf("Queue 3 is empty\n");
       // f3=0,r3=-1;
        }
        else
        {
        printf("Deleted element is: %d\n",q3[f3++]);
        return 1;
        }
}

void display()
	{
	int i,j;
	if(r1==-1 ||f1>r1)
	{
	printf("Queue 1 is empty\n");
	}
	else
	{
	printf("Queue 1 values are:\n");
	for(i=f1;i<=r1;i++)
	{
	printf("%d ",q1[i]);
	printf("\n");
	}
	}


	if(r2==-1 ||f2>r2)
        {
        printf("Queue 2 is empty\n");
        }
        else
        {
        printf("Queue 2 values are:\n");
        for(i=f2;i<=r2;i++)
        {
        printf("%d ",q2[i]);
        printf("\n");
        }
        }


	if(r3==-1 ||f3>r3)
        {
        printf("Queue 3 is empty\n");
        }
        else
        {
        printf("Queue 3 values are:\n");
        for(i=f3;i<=r3;i++)
        {
        printf("%d ",q3[i]);
        printf("\n");
        }
        }

   }
