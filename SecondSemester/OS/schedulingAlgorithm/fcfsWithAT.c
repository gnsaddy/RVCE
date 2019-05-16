#include<stdio.h>
#include<stdlib.h>

void main(){
    int num,exeTime[20],at[20],ct=0,wt[20],tat[20];
    int i,temp=0;
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
    wt[0]=0;
    for(i=1;i<num;i++){
        temp=temp+exeTime[i-1];
        wt[i]=temp-at[i];
        sumWT=sumWT+wt[i];
    }

    printf("\nPid \t\t AT \t\t BT \t\t CT \t\t WT \t\t TAT");
    for(i=0;i<num;i++){
        ct += exeTime[i];
        tat[i]=ct-at[i];
        sumTAT += tat[i];
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d\n",i+1,at[i],exeTime[i],ct,wt[i],tat[i]);
    }
    awt = sumWT/num;
    atat = sumTAT/num;
    printf("\nAverage turn around time : %f",atat);
    printf("\nAverage waiting time : %f",awt);
    printf("\n");
}