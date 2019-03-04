#include <stdio.h>
void main()
{
    int m, n, arr[100][100], r, c, *ptr;
    long int result;
    printf("\nEnter the number rows");
    scanf("%d", &m);
    printf("\nEnter the number of columns");
    scanf("%d", &n);
    printf("\nEnter the elements in the array");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nEnter the index of the element for address");
    scanf("%d%d", &r, &c);
    ptr = &arr[0][0];
    result = (r * m + c) * sizeof(int);
    result = result + (int)ptr;
    printf("\nThe base address is : %u", ptr);
    printf("\nThe Calculated Address is : %u", result);
    printf("\nSize of Integer : %d", sizeof(int));
}