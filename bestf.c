#include <stdio.h>

int main() {
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int alloc[4], i, j;

    for(i = 0; i < 4; i++) {
        alloc[i] = -1;
        int best = -1;
        for(j = 0; j < 5; j++) {
            if(block[j] >= process[i]) {
                if(best == -1 || block[j] < block[best])
                    best = j;
            }
        }
        if(best != -1) {
            alloc[i] = best;
            block[best] -= process[i];
        }
    }

    printf("Best-Fit Allocation:\n");
    for(i = 0; i < 4; i++) {
        printf("Process %d -> ", i+1);
        if(alloc[i] != -1)
            printf("Block %d\n", alloc[i]+1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
