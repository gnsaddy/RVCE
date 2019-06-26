#include<stdio.h>
#include<stdlib.h>

 void fifo(){
    int strLen,refStr[25],frame,m[10],pagefault=0,i,j,k,count=0;
    printf("\nEnter string length : ");
    scanf("%d",&strLen);

    printf("\nEnter ref str \n");
    for(i=0;i<strLen;i++){
        printf("%d-->",i+1);
        scanf("%d",&refStr[i]);
    }

    printf("\nEnter frame number : ");
    scanf("%d",&frame);
    for(i=0;i<strLen;i++){
        m[i]=-1;
    }

    printf("\nReplacement process \n");
    for(i=0;i<strLen;i++){
        for(k=0;k<frame;k++){
            if(m[k]==refStr[i])
                break;
        }

        if(k==frame){
            m[count++]=refStr[i];
            pagefault++;
        }

        for(j=0;j<frame;j++){
            printf("\t%d ",m[j]);
        }

        if(k==frame)
            printf("\tpage fault no. %d ",pagefault);
        printf("\n");
        if(count==frame)
            count=0;
    }
    printf("\nPage fault are %d",pagefault);
}  

void lru(){
    int strLen,refStr[25],frame,m[10],pagefault=0,i,j,k,count[10];
    int flag[25],next=1,min;
    printf("\nEnter string length : ");
    scanf("%d",&strLen);

    printf("\nEnter ref str \n");
    for(i=0;i<strLen;i++){
        printf("%d-->",i+1);
        scanf("%d",&refStr[i]);
        flag[i]=0;
    }

    printf("\nEnter frame number : ");
    scanf("%d",&frame);
    for(i=0;i<frame;i++){
        count[i]=0;
        m[i]=-1;
        
    }

    for(i=0;i<strLen;i++){
        for(j=0;j<frame;j++){
            if(m[j]==refStr[i]){
                flag[i]=1;
                count[j]=next;
                next++;
            }
        }

        if(flag[i]==0){
            if(i<frame){
                m[i]=refStr[i];
                count[i]=next;
                next++;
            }
            else{
                min=0;
                for(j=1;j<frame;j++)
                    if(count[min]>count[j])
                        min=j;
                    m[min]=refStr[i];
                    count[min]=next;
                    next++;
            }
            pagefault++;
        }
        for(j=0;j<frame;j++)
            printf("\t%d",m[j]);
        if(flag[i]==0)
            printf("\tpagefault no. %d",pagefault);
        printf("\n");
    }
    printf("\ntotal pagefault are %d \n",pagefault);
}


void optimal(){
    int strLen,refStr[25],frame,m[10],pagefault=0,i,j,k;
    int temp[10],pos,max,flag1,flag2,flag3;
    printf("\nEnter string length : ");
    scanf("%d",&strLen);

    printf("\nEnter ref str \n");
    for(i=0;i<strLen;i++){
        printf("%d-->",i+1);
        scanf("%d",&refStr[i]);
    }

    printf("\nEnter frame number : ");
    scanf("%d",&frame);
    for(i=0;i<strLen;i++){
        m[i]=-1;
    }

    printf("\npage replacement process\n");
    for(i=0;i<strLen;i++){
        flag1=flag2=0;
        for(j=0;j<frame;j++){
            if(m[j]==refStr[i]){
                flag1=flag2=1;
                break;
            }
        }

        if(flag1==0){
            for(j=0;j<frame;j++){
                if(m[j]==-1){
                    pagefault++;
                    m[j]=refStr[i];
                    flag2=1;
                    break;
                }
            }
        }

        if(flag2==0){
            flag3=0;
            for(j=0;j<frame;j++){
                temp[j]=-1;
                for(k=i+1;k<strLen;k++){
                    if(m[j]==refStr[k]){
                        temp[j]=k;
                        break;
                    }
                }
            }

            for(j=0;j<frame;j++){
                if(temp[j]==-1){
                    pos=j;
                    flag3=1;
                    break;
                }
            }

            if(flag3==0){
                max=temp[0];
                pos=0;
                for(j=1;j<frame;j++){
                    if(temp[j]>max){
                        max=temp[j];
                        pos=j;
                    }
                }
            }
            m[pos]=refStr[i];
            pagefault++;
        }
        printf("\n");
        for(j=0;j<frame;j++)
            printf("\t%d",m[j]);
        printf("\tpagefault no. %d ",pagefault);
    }
    printf("\ntotal page fault is %d : ",pagefault);

}

void main(){
    int ch;
    while(1){
        printf("\n1-FIFO\n2-LRU\n3-OPTIMAL\n");
        printf("\nEnter choice\t");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            fifo();
            break;
        case 2:
            lru();
            break;
        case 3:
            optimal()for(j=dloc;j>=0;j++)
                        printf("%d-->",queue[j]);
;
            break;
        
        default:
            printf("\nInvalid choice");
            break;
        }
    }
}