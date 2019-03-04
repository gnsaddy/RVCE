#include<stdio.h>
#include<stdlib.h>

int ar[10][10],visited[10],vertex,size;
void dfs(int);
int main(){
    int i,j,source,count=0;
    printf("\nEnter the no. of nodes in the graph\n");
    scanf("%d", &size);
    printf("\nEnter the adjacency matrix \n");
    for (i = 1; i <= size; i++)
    {
        visited[i]=0;
        for (j = 1; j <= size; j++)
        {
            scanf("%d", &ar[i][j]);
        }
    }
    printf("\nThe adjacency matrix shown as\n");
    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= size; j++)
        {
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }    
    printf("\nEnter the starting node for Depth First search\n");
    scanf("%d", &source);
    dfs(source);
    
    for(i=1;i<=size;i++)
        if(visited[i])
            count++;
            if(count==size)
            printf("\n DFS connection \n");
            else
            printf("\n Can not generate DFS connection\n");
    }
void dfs(int vertex)
{
    int i;
    visited[vertex] = 1;
    for (i = 1; i <= size; i++)
    {
        if (ar[vertex][i] == 1 && visited[i] == 0)
        {
            printf("DFS is : %d->%d\n", vertex, i);
            dfs(i);
        }
    }
}
