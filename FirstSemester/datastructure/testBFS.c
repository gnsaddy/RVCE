#include<stdio.h>
#include<stdlib.h>

int ar[10][10],q[10],v[10],i,j,s,size;
int f=0,r=-1;

void main(){
    printf("Enter matrix size\n");
    scanf("%d",&size);
    printf("Enter elements in matrix\n");
    for(i=1;i<=size;i++){
        v[i]=0;
        q[i]=0;
        for(j=1;j<=size;j++){
            scanf("%d",&ar[i][j]);
        }
    }

    printf("matrix : \n");
    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
            printf(" %d ",ar[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter starting vertex\n");
    scanf("%d",&s);
    bfs(s);
    printf("Rechable node from vertex %d is ",s);
    for(i=1;i<size;i++){
        printf("%d->",q[i]);
    }
}

void bfs(int s){
    q[++r]=s;
    v[s]=1;
    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
            if(ar[q[f]][j] && !v[j]){
                q[++r]=j;
                v[j]=1;
            }               

        }
        f++;
    }
}