#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int top=-1,n,a[100];

void push(int val)
{
 a[++top]=val;
}

int pop()
{
 return a[top--];
}

void display()
{
 printf("Evluated value is %d\n",a[top]);
}

void main()
{
 char str[100];
 int i,j,m=1,ch=0,ch1=0,op1,op2;
 printf("Enter the expression\n");
 scanf("%s",str);
 for(i=0;i<strlen(str);i++)
 {
  switch(str[i])
  {
   case '+':
   case '-':
   case '*':
   case '/':
   case '%':
   case '$':ch++;
            break;
   default:ch1++;
  }
 }
 if((ch==ch1-1) && (isalpha(str[0]) || isdigit(str[0])) && (isalpha(str[1]) || isdigit(str[1])))
 {
  for(i=0;i<strlen(str);i++)
  {
   if(isalpha(str[i])!=0)
   {
    printf("Enter the value for %c: ",str[i]);
    scanf("%d",&n);
    push(n);
   }
   else if(isdigit(str[i])!=0)
   {
    n=str[i]-'0';
    push(n);
   }
   else
   {
    op1=pop();
    op2=pop();
    switch(str[i])
    {
      case '+':push(op2+op1);
	       break;
      case '-':push(op2-op1);
	       break;
      case '*':push(op2*op1);
	       break;
      case '/':push(op2/op1);
	       break;
      case '%':push(op2%op1);
	       break;
      case '$':for(j=0;j<op1;j++)
	       m=m*op2;
	       push(m);
    }
   }
  }
  display();
 }
 else
  printf("Invalid expression\n");
}