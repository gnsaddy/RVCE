#include<stdio.h>
int n,p[10][10];
void path()
{
	int i,j,k;
	for(k=0;k<n;k++)
	   for(i=0;i<n;i++)
                for(j=0;j<n;j++)
			if(p[i][j]==0 && p[i][k]==1 && p[k][j]==1)
				p[i][j]=1;

}

void main()
{
	int i,j;
	printf("\nEnter number of nodes : ");
	scanf("%d",&n);
	printf("\nEnter adjacency matrix : ");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&p[i][j]);
	path();
	printf("\nPath matrix \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		    printf("%d ",p[i][j]);
		}
		printf("\n");
	}

}
