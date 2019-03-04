#include <stdio.h>
#define MAX 20
int size;

void linear_search(int[], int);

int main()
{
    long array[MAX], search;

    printf("Input number of elements in array\n");
    scanf("%ld", &size);

    printf("Input  numbers\n");

    for (int i  = 0; i < size; i++)
        scanf("%ld", &array[i]);

    printf("\nElements are\n");

    for (int i = 0; i < size; i++)
        printf("%d", array[i]);

    printf("Input a number to search\n");
    scanf("%ld", &search);

    linear_search(array, search);
    binary(array,search);

    
}

void linear_search(int a[], int find)
{
    int i;
    printf("\n liner serarch\n");
    
        for(i=0;i<=size;i++){
            if(a[i]==find){
                printf("\nNumber %d found at location %d",find,i);
                break;
            }
            
            if(i>find)
            {
                printf("Not found\n");
                break;
            }
        }
    }

void binary(int a[],int find){
    int start=0;
    int end=(size-1);
    int mid;

    while(start<=end){
        mid=(start+end)/2;
        if(find==a[mid]){
            printf("Element % found at position %d :",find,mid+1);
            break;
        }
        else if(find<a[mid])
        end=(mid-1);
        else{
            start = (mid+1);
            printf("\n not found");
            break;
        }
    }
}
    
