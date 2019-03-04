#include<stdio.h>
void main(){
    int rowSize, colSize, arr[100][100], row, col, *ptr;
    long int result;
    printf("\nEnter the number rows");
    scanf("%d", &rowSize);
    printf("\nEnter the number of columns");
    scanf("%d", &colSize);
    printf("\nEnter the elements in the array");

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n Matrix is :- \n");
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the index of the element for address");
    scanf("%d%d", &row, &col);
    ptr = &arr[0][0];
    result = (row * colSize + col) * sizeof(int);
    result = result + (int)ptr;
    printf("\nThe base address is : %u", ptr);
    printf("\nThe Calculated Address is : %u", result);
    printf("\nSize of Integer : %d", sizeof(int));
}
