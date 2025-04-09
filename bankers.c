#include<stdio.h>
#include<stdbool.h>

struct process{
    int id;
    int max[10];
    int alloc[10];
    int need[10];
    bool finished;
};

int main(){
    int n, r;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resouces: ");
    scanf("%d", &r);

    struct process p[n];
    int available[r];

    printf("Enter Max matrix:\n");
    for(int i=0;i<n;i++){
        p[i].id = i;
        for(int j=0;j<r;j++){
            scanf("%d", &p[i].max[j]);
        }
    }

    printf("Enter allocation matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            scanf("%d", &p[i].alloc[j]);
            //calculation of need
            p[i].need[j] = p[i].max[j] - p[i].alloc[j];
        }
        p[i].finished = false;
    }

    printf("Enter available resources:\n");
    for(int i=0;i<r;i++){
        scanf("%d", &available[i]);
    }

    int safeseq[n], count = 0;

    while(count<n){
        bool found = false;
        for(int i=0;i<n;i++){
            if(!p[i].finished){
                bool canrun = true;
                for(int j=0;j<r;j++){
                    if(p[i].need[j]>available[j]){
                        canrun = false;
                        break;
                    }
                }
                if(canrun){
                    for(int j=0;j<r;j++){
                        available[j]+=p[i].alloc[j];
                    }
                    safeseq[count++] = p[i].id;
                    p[i].finished = true;
                    found = true;
                }
            }
        }
        if(!found){
            printf("\nSystem is not in a safe state.\n");
            return 0;
        }
    }

    printf("System is in safe state and sequence: ");
    for(int i=0;i<n;i++){
        printf("P%d ", safeseq[i]);
    }

    return 0;
}