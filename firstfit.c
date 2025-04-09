#include<stdio.h>
int main(){
    int block[] = {100,500,200,300,600};
    int process[] = {212, 417, 112, 426};
    int alloc[4];

    for(int i=0;i<4;i++){
        alloc[i] = -1;
        for(int j=0;j<5;j++){
            if(block[j]>=process[i]){
                alloc[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    printf("First-Fit allocation:\n");
    for(int i=0;i<4;i++){
        printf("Process %d -> ", i+1);
        if(alloc[i]!=-1){
            printf("Block %d\n", alloc[i]+1);
        }
        else
            printf("Not allocated\n");
    }
    return 0;
}