#include<stdio.h>
#include<stdlib.h>

#define MAX 10
int size,arr[MAX];

void sort(int arr[]);
void linear();
void binary();

void sort(int arr[]){
    int i,j,temp;

    for(i=0;i<size;i++){
        for(j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted arrays is :\n");
    for (i=0;i<size;i++){        
        printf("%d\t ",arr[i]);
    }
}

void linear(int ele){
    int i;
    int flag = 0;
    printf("Linear search \n");
    for (i=0;i<size;i++){
        if(arr[i] == ele){
            flag = 1;
            break;
        }    
    }
    if(flag == 1){
        printf("\nElement %d found at %d  ", ele, i + 1);
    }
    else{
        printf("Element not found \n");
    }
}

void binary(int ele){
    int start=0,end,mid,i;
    int flag = 0;
    end = size-1;
    printf("\nBinary search \n");
    
    while(start<=end){
        mid = (start + end)/2;

        if (ele == arr[mid]){
            flag =1;
            break;
        }
        else if(arr[mid]>ele){
            end = mid-1;
        }
        else{
            start = mid +1;
        }
    }
    if(flag == 1){
        printf("\nelement found %d at %d ", ele, mid+1);
    }
    else{
        printf("Not found \n");
    }
}

void main(){
    int element,i;
    printf("\nEnter Size of array \n");
    scanf("%d",&size);

    printf("Enter element in array \n");
    for (int i=0;i<size;i++){
        scanf("%d",&arr[i]);
        }    
        while (1)
        {
            printf("\n1-Linear search\n2-Binary search\n");
            printf("Enter choice\n");
            int ch = 0;
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                printf("\nEnter element to search \n");
                scanf("%d", &element);
                linear(element);
                break;
            case 2:
                sort(arr);
                printf("\nEnter element to search \n");
                scanf("%d", &element);
                binary(element);
                break;
        
            default:
                break;
        }
    } 
}