#include<stdio.h>
int main(){
    int block[] = {100,500,200,300,600};
    int process[] = {1,417,112,426};
    int alloc[4];

    for(int i=0;i<4;i++){
        alloc[i] = -1;
        int worst = -1;
        for(int j=0;j<5;j++){
            if(block[j]>=process[i]){
                if(worst==-1 || block[j]>block[worst]){
                    worst = j;
                }
            }
        }
        if(worst != -1){
            alloc[i] = worst;
            block[worst] -= process[i];
        }
    }

    printf("Worst-fit allocation:\n");
    for(int i=0;i<4;i++){
        printf("Process %d -> ", i+1);
        if(alloc[i]!=-1){
            printf("Block %d\n", alloc[i]+1);
        }
        else{
            printf("Not allocated\n");
        }
    }
    return 0;
}