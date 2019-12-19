#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

struct timeval start,end;
void quick_sort(int[],int,int);
int partition(int[],int,int);

int main()
{
	int a[600],n,i,it,k;
	FILE *fp;
	fp = fopen("quickTime.txt","w");
	printf("\nEnter the number of iterations : ");
	scanf("%d",&it);
for(k=1;k<=it;k++){
	printf("\nHow many elements :- ");
	scanf("%d",&n);
	printf("\nEnter array elements:\n");
	for(i=0;i<n;i++)
		a[i] = rand()%1000;
	for(i=0;i<n;i++){
		printf(" %d ",a[i]);
	}
	gettimeofday(&start,0);
	quick_sort(a,0,n-1);
	gettimeofday(&end,0);
	float calTime = end.tv_usec - start.tv_usec;
	printf("\nArray after sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\nQuicsort takes %f ms to sort an array of length %d : ",calTime,n);
	fprintf(fp,"%d \t %f \n",n,calTime);
}
return 0;
}

void quick_sort(int a[],int low,int up)
{
	int j;
	if(low<up)
	{
		j=partition(a,low,up);
		quick_sort(a,low,j-1);
		quick_sort(a,j+1,up);
	}
}

int partition(int a[],int low,int up)
{
	int v,i,j,temp;
	v=a[low];
	i=low;
	j=up+1;
	while(i<j)
	{
		do{
			i++;
		}while(a[i]<v&&i<=up);
		do{
			j--;
		}while(v<a[j]);
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}

	a[low]=a[j];
	a[j]=v;
	return(j);
}

