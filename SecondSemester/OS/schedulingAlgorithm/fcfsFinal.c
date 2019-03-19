#include<stdio.h>
#include<stdlib.h>

int main(){
    int num, exeTime[20],waitTime=0,tat=0;
    int i;
    float awt,atat;
    float sumWT,sumTAT;

    printf("\nEnter the number of process : ");
    scanf("%d",&num);

    for(i=0;i<num;i++){
        printf("\nEnter execution time for process %d : ",i+1);
        scanf("%d",&exeTime[i]);
    }

    printf("\nPid \t\t AT \t\t BT \t\t WT \t\t TAT");
    for(i=0;i<num;i++){
        int at=0;
        tat = exeTime[i] + waitTime;
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d",i+1,at,exeTime[i],waitTime,tat);
        sumWT += waitTime;
        sumTAT += tat;
        waitTime += exeTime[i];
    }

    awt = sumWT/num;
    atat = sumTAT/num;
    printf("\nAverage turn around time : %f",atat);
    printf("\nAverage waiting time : %f",awt);
    printf("\n");
}