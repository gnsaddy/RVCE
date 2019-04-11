#include<stdio.h>
#include<stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main(){
    int num,pid[20],exeTime[20],at[20],wt=0,ct=0,tat=0,sumWT=0,sumTAT=0;
    int i,j,temp;
    float awt,atat;

    printf("\nEnter the number of process : ");
    scanf("%d",&num);

    for(i=0;i<num;i++){
        printf("\nEnter execution time for process %d : ",i+1);
        scanf("%d",&exeTime[i]);
        pid[i]=i+1;
    }
    for(i=0;i<num;i++){
        printf("\nEnter arrival time for process %d : ",i+1);
        scanf("%d",&at[i]);
    }

for(int i=0;i<num;i++){
    for(int j=0;j<num;j++){
        if(exeTime[i]<exeTime[j]){
           swap(&exeTime[i],&exeTime[j]);            
            swap(&at[i],&at[j]);
            swap(&pid[i],&pid[j]);
        }
    }
}

printf("\nPid \t\tAt \t\tBT \t\tCT \t\tWT \t\tTAT");

for (int i=0;i<num;i++){
    ct += exeTime[i];
    tat=ct-at[i];
    wt=tat-exeTime[i];
    sumWT += wt;
    sumTAT += tat;
    printf("\np%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d\n",pid[i],at[i],exeTime[i],ct,wt,tat);

}

awt = sumWT/num;
atat= sumTAT/num;
printf("AWT %f ",awt);
printf("ATAT %f ",atat);

}
    
