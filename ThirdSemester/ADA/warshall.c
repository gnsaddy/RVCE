#include<stdio.h>
int n,a[10][10],p[10][10];

void path()
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			p[i][j]=a[i][j];
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(p[i][j]==0 && p[i][k]==1 && p[k][j]==1)
				{
					   p[i][j]=1;
				}
			}
		}
	}
}
void main()
{
	
	int i,j,k=0;
	printf("------Warshall's Algorithm---------\n");
	printf("Enter the number of vertices::");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	path();
	printf("The path matrix is::\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			k++;
			printf("%d\t",p[i][j]);
			//    printf("\n");
			if(k==n)
			{
				k=0;
				printf("\n");
			}
		}
	}
}

