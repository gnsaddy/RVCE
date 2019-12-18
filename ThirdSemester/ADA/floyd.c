#include<stdio.h>
int p[20][20],n;
int min(int,int);
int path()
{
	int i,j,k;
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(i==j)
					p[i][j]=0;
				else
					p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
void main()
{
	int i,j;
	printf("\n Enter the no of vertices:");
	scanf("%d",&n);
	printf("\n Enter the adjacency matrix:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&p[i][j]);
			if(p[i][j]==0 && i!=j)
				p[i][j]=999;
		}
	}
	path();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
	 for(i=0;i<n;i++)
	{
        	for(j=0;j<n;j++)	
			{
				if(i!=j)
					if(p[i][j]==999)
						printf("<%d,%d> is infinite\n",i+1,j+1);
					else
						printf("<%d,%d> is %d\n",i+1,j+1,p[i][j]);
	}		}
}


