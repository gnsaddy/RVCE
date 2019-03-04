#include <stdio.h>
#include<malloc.h>
#include <stdlib.h>
void main() {
	int i,size;
	int *ar1,*ar2,*finalAr;
	printf("How many Elements in each array...\n");
	scanf("%d", &size);
	ar1 = (int *) malloc(size*sizeof(int));
	ar2 = (int *) malloc(size*sizeof(int));
	finalAr =( int *) malloc(size*sizeof(int));
	printf("Enter Elements of First List\n");
	for (i=0;i<size;i++) {
		scanf("%d",ar1+i);
	}
	printf("Enter Elements of Second List\n");
	for (i=0;i<size;i++) {
		scanf("%d",ar2+i);
	}
	for (i=0;i<size;i++) {
		*(finalAr+i) = *(ar1+i) + *(ar2+i);
	}
	printf("Resultant List is\n");
	for (i=0;i<size;i++) {
		printf("%d\n",*(finalAr+i));
	}
}