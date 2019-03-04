#include <stdio.h>
#include <stdlib.h>
int a[10][10], q[10], v[10], f = 0, r = -1, i, j, n, l;
void bfs(int);

int main()
{
    printf("Size of number of vertex  \n");
    scanf("%d", &n);
    printf("Enter the adjancey matrix\n");
    for (i = 1; i <= n; i++)
    {
        v[i] = 0;
        q[i] = 0;
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nMatrix is :- \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    printf("\nStarting\n");
    scanf("%d", &l);
    bfs(l);
    printf("Reachable from %d is: ", l);
    for (i = 1; i < n; i++)
        printf("%d->", q[i]);
    printf("\n");
}

void bfs(int m)
{
    q[++r] = m;
    v[m] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (a[q[f]][j] && !v[j])
            {
                q[++r] = j;
                v[j] = 1;
            }
        }
        f++;
    }
}