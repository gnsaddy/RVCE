#include<stdio.h>
#include<stdlib.h>
/*
void fifo(){
	int strLength,refStr[25],frame,pageFault=0,count=0,m[10],i,j,k;
	printf("\nEnter the string length : ");
	scanf("%d",&strLength);
	printf("\nEnter the ref string \n");
	for(i=0;i<strLength;i++){
		printf("\n%d--> ",i+1);
		scanf("%d",&refStr[i]);
	}

	printf("\nEnter the number of frame : ");
	scanf("%d",&frame);

	for(i=0;i<frame;i++)
		m[i]=-1;

	for(i=0;i<strLength;i++){
		for(k=0;k<frame;k++){
			if(m[k]==refStr[i])
				break;
			}
		if(k==frame){
			m[count++]=refStr[i];
			pageFault++;
		}

		for(j=0;j<frame;j++){
			printf("\t %d ",m[j]);
		}

		if(k==frame){
			printf("\tPF no. %d",pageFault);
		}
		printf("\n");
		if(count==frame)
			count=0;
	}

	printf("\nTotal page fault are %d ",pageFault);
}

*/
void main(){
	int strLen,refStr[25],frame,m[10],count[10],flag[25],next=1;
	int i,j,k,min=0,pagefault=0;

	printf("\nEnter string length : ");
	scanf("%d",&strLen);
	printf("\nEnter ref string\n");
	for(i=0;i<strLen;i++){
		printf("%d-->",i+1);
		scanf("%d",&refStr[i]);
		flag[i]=0;
	}

	printf("\nEnter the number of frame :");
	scanf("%d",&frame);

	for(i=0;i<frame;i++){
		m[i]=-1;
		count[i]=0;
	}

	printf("\n Page replacement process\n");
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
			printf("\t %d ",m[j]);
		if(flag[i]==0)
			printf("\t page fault no. %d",pagefault);
			printf("\n");
	}

	printf("\ntotal pagefault are %d :",pagefault);
}
