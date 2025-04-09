#include<stdio.h>

int main(){
    int blocks[] = {100,200,412,600,300};
    int process[] = {500, 200, 300 , 400};
    int alloc[4];

    for(int i=0;i<4;i++){
        alloc[i] = -1;
        for(int j=0;j<5;j++){
            if(blocks[j]>=process[i]){
                blocks[j] -= process[i];
                alloc[i] = j;
                break;
            }
        }
    }

    for(int i=0;i<4;i++){
        printf("process %d -> ", i+1);
        if(alloc[i]!=-1){
            printf("Block %d\n", alloc[i]);
        }
        else{
            printf("Not allocated\n");
        }
    }
}