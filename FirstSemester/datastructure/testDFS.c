#include<stdio.h>

void dfs(int v);

typedef enum boolean{
    false,
    true
}bool;

int ar[10][10], size;
bool visited[10];


void main(){
    int i, j,v;

    printf("Enter the size of the matrix\n");
    scanf("%d",&size);
    printf("Enter elements in adjacency matrix\n");
    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
            scanf("%d",&ar[i][j]);
        }
    }
    printf("Adjancey matric is \n");
    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
            printf("%d ",ar[i][j]);
        }
        printf("\n");
    }
        

    while(1){
        printf("Enter the starting node \n");
        scanf("%d",&v);
        for(i=1;i<=size;i++)
            visited[i]=false; 
        dfs(v);
    }
}
    void dfs(int v){
        int i;
        int stack[10],top=-1,pop;

        stack[++top] = v;
        while(top>=0){
            pop = stack[top];
            top--;
            if(visited[pop]==false){
                printf("%d-->",pop);
                visited[pop]=true;
            }
            else
                continue;
                for(i=size;i>=1;i--){
                    if(ar[pop][i]==1 && visited[i]==false){
                        stack[++top] = i;
                    }
                }
        }
        
    }







