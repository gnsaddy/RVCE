#include<stdio.h>
#include<stdlib.h>

int main(){
    int listI;
    float listF;
    char listC;

    int *ptrI = listI;
    //float *ptrF:
   // ptrF = listF;


    printf("%d", sizeof(listI));
    printf("%d", sizeof(ptrI));
    printf("%d", sizeof(*ptrI));
  //  printf("%d", sizeof(listF));
    //printf("%d", sizeof(ptrF));



}
