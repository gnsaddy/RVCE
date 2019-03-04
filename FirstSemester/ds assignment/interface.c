#include<stdio.h>
#include<stdlib.h>
#include"sort.h"
#define MAX 100

void main(int argc, char const *argv[])
{
  int arr[MAX], i, step, temp;
  // atoi() is used to convert string to integer
  int limit = atoi(argv[1]);

  if (argc > 2)
  {
    printf("No more arguments. Only two argument is allowed.\n");
    exit(1);
  }

  // ask user for number of elements to be sorted
  printf("\n************************************************\n");
  printf("Enter the number of elements to be sorted: ");
  //scanf("%d", &limit);
  printf("\n************************************************\n");
  // input elements if the array
  for (i = 0; i < limit; i++)
  {
    printf("Element %d is %d \n", i + 1, arr[i] = rand() % 100 + 1);
    //arr[i] = rand() % 100 + 1;
    }
    printf("\n************************************************\n");
    printf("Array elements are :- \n");
    for(i = 0; i < limit; i++)
    {
        printf("\t%d",arr[i]);
    }


    printf("\n************************************************\n");

    while (1) {
      int ch;
      printf("\n************************************************\n");
      printf("\n1-Bubble Sort \n2-Selection Sort \n3-Insertion Sort \n4-Merge Sort \n5-Quick Sort \n6-Heap Sort \n7-Exit\n");
      printf("\n************************************************\n");
      printf("Enter your choice\n");
      scanf("%d",&ch);

      printf("\n************************************************\n");

      switch (ch) {
        case 1:
          printf("\n************* Bubble sort *************\n");
          bubbleSort(arr,limit);
          printf("\n************************************************\n");
          break;
        case 2:
          printf("\n************* Selection sort *************\n");
          SelectionSort(arr,limit);
          printf("\n************************************************\n");
          break;
        case 3:
        printf("\n************* Insertion sort *************\n");
        InsertionSort(arr,limit);
        printf("\n************************************************\n");
        break;
        case 4:
        printf("\n************* Merge sort *************\n");
        mergeSort(arr, 0, limit - 1);
        printf("\nSorted array using merge sort \n");
        for (i=0; i < limit; i++)
        printf("%d ", arr[i]);
        printf("\n************************************************\n");
        break;
        case 5:
        printf("\n************* Quick sort *************\n");
        quicksort(arr, 0, limit - 1);
        for (i=0; i < limit; i++)
        printf("%d ", arr[i]);
        printf("\n************************************************\n");
        break;
        case 6:
        printf("\n************* Heap sort *************\n");
        heapsort(arr, limit);
        break;
        case 7:
        exit(0);



      }

        }
}
