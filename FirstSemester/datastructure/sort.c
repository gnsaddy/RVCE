#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int size;

void bubbleSort(int arr[]);
void SelectionSort(int arr[]);
void InsertionSort(int arr[]);

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void print(int arr[])
{
    printf("\nSorted Array : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void main()
{

    int arr[MAX], i, limit, step, temp;
    printf("Enter the limit of array ");
    scanf("%d", &size);

    printf("Enter array element \n");
    for (i = 0; i < size; i++)
    {
        printf("Element %d is %d \n", i + 1, arr[i] = rand() % 100 + 1);
    }

    printf("Array elements are :- \n");
    for (i = 0; i < size; i++)
    {
        printf("\t%d", arr[i]);
    }

    while (1)
    {
        int ch;
        printf("\n1-Bubble Sort \n2-Selection Sort \n3-Insertion Sort \n4-Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            bubbleSort(arr);
            break;
        case 2:
            SelectionSort(arr);
            break;
        case 3:
            InsertionSort(arr);
            break;
    }
}
}

void bubbleSort(int arr[])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap the elements
                swap(&arr[j], &arr[j + 1]);
                }
        }
    }
    // print the sorted array
    print(arr);
}

void SelectionSort(int arr[])
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        int Imin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[Imin])
                Imin = j;
         }
         swap(&arr[Imin], &arr[i]);
    }
    print(arr);
}

void InsertionSort(int arr[])
{
    int i, hole, value;
    for (i = 1; i < size; i++)
    {
        value = arr[i];
        hole = i;
        while (hole > 0 && arr[hole - 1] > value)
        {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = value;
    }
    print(arr);
   
}

