#include<stdio.h>
#include<stdlib.h>


int a,b,u,v,i,j,n,ne=1;
int visited[10] = {0};
int min,mincost=0,cost[10][10];

int main(){
	printf("\nEnter the number of vertices : ");
	scanf("%d",&n);

	printf("\nEnter the value in adjacency matrix : \n");
	for(i=1;i<=n;i++){
		printf("\nRow %d elements : ",i);
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}

	visited[1]=1;

	while(ne<n){
		for(i=1,min=999;i<=n;i++)
			for(j=1;j<=n;j++)
				if(cost[i][j]<min)
					if(visited[i]!=0){
						min = cost[i][j];
						a = u = i;
						b = v = j;
					}

		if(visited[u] == 0 || visited[v] == 0){
			printf("\n %d: (%d %d) is cost : %d ",ne++,a,b,min);
			mincost += min;
			visited[b] = 1;
		}

		cost[a][b] = cost[b][a] = 999;
	}
	printf("\nMin cost %d : \n",mincost);
	return(0);
}
