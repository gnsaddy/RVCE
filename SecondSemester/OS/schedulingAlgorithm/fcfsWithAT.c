#include<stdio.h>
#include<stdlib.h>

void main(){
    int num,exeTime[20],at[20],ct=0,wt=0,tat=0;
    int i;
    float awt,atat;
    float sumWT,sumTAT;

    printf("\nEnter the number of process : ");
    scanf("%d",&num);

    for(i=0;i<num;i++){
        printf("\nEnter execution time for process %d : ",i+1);
        scanf("%d",&exeTime[i]);
    }

    for(i=0;i<num;i++){
        printf("\nEnter arival time for process %d : ",i+1);
        scanf("%d",&at[i]);
    }

    printf("\nPid \t\t AT \t\t BT \t\t CT \t\t WT \t\t TAT");
    for(i=0;i<num;i++){
        ct += exeTime[i];
        tat=ct-at[i];
        wt=tat-exeTime[i];
        sumWT += wt;
        sumTAT += tat;
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d\n",i+1,at[i],exeTime[i],ct,wt,tat);
    }
    awt = sumWT/num;
    atat = sumTAT/num;
    printf("\nAverage turn around time : %f",atat);
    printf("\nAverage waiting time : %f",awt);
    printf("\n");


}