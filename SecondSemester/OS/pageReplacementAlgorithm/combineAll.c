#include<stdio.h>
#include<stdlib.h>

void fifo(){
   int i, j, k, frame, pageFault=0, count=0, refStr[25], m[10], strLength;
    printf("\n Enter the length of reference string -- ");
    scanf("%d",&strLength);
    printf("\n Enter the reference string \n ");
    for(i=0;i<strLength;i++){
        printf("%d -->",i+1);
        scanf("%d",&refStr[i]);
    }
    printf("\n Enter no. of frames -- ");
    scanf("%d",&frame);
    for(i=0;i<frame;i++)
        m[i]=-1;
    printf("\n The Page Replacement Process is -- \n");
    for(i=0;i<strLength;i++){
        for(k=0;k<frame;k++){
            if(m[k]==refStr[i])
                break;
        }
        if(k==frame){
            m[count++]=refStr[i];
            pageFault++;
        }
        for(j=0;j<frame;j++)
            printf("\t%d",m[j]);
        if(k==frame)
        printf("\tPF No. %d",pageFault);
        printf("\n");
        if(count==frame)
            count=0;
    }
    printf("\n The number of Page Faults using FIFO are %d\n",pageFault,"\n");
}

void lru(){
    int i, j , k, min, rs[25], m[10], count[10], flag[25], n, f, pf=0, next=1;
    printf("Enter the length of reference string -- ");
    scanf("%d",&n);
    printf("Enter the reference string \n ");
    for(i=0;i<n;i++) {
        printf("%d -->",i+1);
        scanf("%d",&rs[i]);
        flag[i]=0;
    }
    printf("Enter the number of frames -- ");
    scanf("%d",&f);
    for(i=0;i<f;i++){
        count[i]=0;
        m[i]=-1;
    }
    printf("\nThe Page Replacement process is -- \n");
    for(i=0;i<n;i++){
        for(j=0;j<f;j++){
            if(m[j]==rs[i]){
                flag[i]=1;
                count[j]=next;
                next++;
            }
        }
        if(flag[i]==0){
            if(i<f){
                m[i]=rs[i];
                count[i]=next;
                next++;
            }
            else{
                min=0;
                for(j=1;j<f;j++)
                if(count[min] > count[j])
                    min=j;
                m[min]=rs[i];
                count[min]=next;
                next++;
            }
        pf++;
        }
        for(j=0;j<f;j++)
        printf("%d\t", m[j]);
        if(flag[i]==0)
        printf("PF No. -- %d" , pf);
        printf("\n");
    }
    printf("\nThe number of page faults using LRU are %d",pf);
}

void main(){
    fifo();
    lru();
}

