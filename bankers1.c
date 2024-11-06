#include<stdio.h>
#include<stdlib.h>
int allocated[20],required[20],need[20];

void main(){
    int n;
    printf("\n enter number of process:");
    scanf("%d",&n);
    int max = 10 , allocatecount = 0;
    for(int i=0;i<n;i++){
       printf("\n required resources for process %d :",i+1);
       scanf("%d",&required[i]);
    }
    
    for(int i=0;i<n;i++){
       printf("\n allocated resources for process %d :",i+1);
       scanf("%d",&allocated[i]);
       allocatecount+=allocated[i];
       need[i] = required[i]-allocated[i];
    }
    
    int available = max - allocatecount;
    int sequence = 0;
    int ans[n],ind=0;
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(need[j]>available || need[j]==0){
                continue;
           }
           else{
                ans[ind++]=j+1;
                sequence++;
                available+=allocated[j];
                need[j]=0;
           }
       }
    }
    
    if(sequence<n){
        printf("\n System is in unsafe state");
    }
    else{
       printf("\n System is in safe state \n");
       for(int i=0;i<n;i++){
         printf("P%d->",ans[i]);
       }
    }
}


