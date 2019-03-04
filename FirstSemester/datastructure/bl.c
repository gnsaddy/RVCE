#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int n, a[MAX], ele, i, flag = 0;

void linear(int s[], int m, int key)
{
    for (i = 0; i < m; i++)
    {
        if (s[i] == key)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        printf("Element is found in %d position\n", i + 1);
    else
        printf("Element not found\n");
}

void binary(int s[], int m, int key)
{
    int flag = 0, high = m - 1, low = 0, mid, j, temp;
    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < m - i - 1; j++)
        {
            if (s[j] > s[j + 1])
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    printf("Sorted list is:\n");
    for (i = 0; i < m; i++)
        printf("%d\t", s[i]);
    printf("\n");
    //printf("%d %d\n",low,high);
    while (high > low)
    {
        mid = (high + low) / 2;
        if (key == s[mid])
        {
            flag = 1;
            break;
        }
        else if (s[mid] > key)
        {
            high = mid - 1;
            low = 0;
        }
        else
        {
            low = mid + 1;
            high = n - 1;
        }
    }
    if (flag == 1)
        printf("Element is found in %d position\n", mid + 1);
    else
        printf("Element is not found\n");
}

void main()
{
    int ch;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    if (MAX < n || n == 0)
    {
        printf("Enter the value within range\n");
        exit(0);
    }
    printf("Enter the array elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    do
    {
        printf("\n1.Linear Search\n2.Binary Search\n3.Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the search element\n");
            scanf("%d", &ele);
            linear(a, n, ele);
            break;
        case 2:
            printf("Enter the search element\n");
            scanf("%d", &ele);
            binary(a, n, ele);
            break;
        default:
            exit(0);
        }
    } while (1);
}