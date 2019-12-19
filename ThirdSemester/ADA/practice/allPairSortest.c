#include<stdio.h>
#include<stdlib.h>

int n,p[20][20];
int min(int a,int b){
	if(a<b)
		return a;
	else
		return b;
}


void floyd(){
	int i,j,k;
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				if(i==j)
					p[i][j]=0;
				else
					p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
			}
}

void warshall(){
	int i,j,k;
	 for(k=0;k<n;k++)
                for(i=0;i<n;i++)
                        for(j=0;j<n;j++){
				if(p[i][j]==1 || p[i][k]==1 && p[k][j]==1)
					p[i][j]=1;
			}
}

void main(){
	int i,j;

	printf("\nEnter the number of vertices : ");
	scanf("%d",&n);

	printf("\nEnter adjacency matrix : \n");
	for(i=0;i<n;i++){
		printf("\nRow %d element : ",i+1);
		for(j=0;j<n;j++){
			scanf("%d",&p[i][j]);
			if(p[i][j]==0 && i!=j)
				p[i][j]=999;
		}
	}

	floyd();

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d  ",p[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j){
				if(p[i][j]==999)
					printf("\n(%d %d) is infinity ",i+1,j+1);
				else
					printf("\n(%d %d) is : %d  ",i+1,j+1,p[i][j]);
			}
		}
	}
}
















