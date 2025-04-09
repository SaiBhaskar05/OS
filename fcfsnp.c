#include<stdio.h>

struct process{
    int id;
    int bursttime;
    int waitingtime;
    int turnaroundtime;
    int completiontime;
};

int main(){
    int n;
    struct process p[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        p[i].id = i+1;
        printf("Enter burst time for process %d: ", p[i].id);
        scanf("%d", &p[i].bursttime);
    }

    p[0].waitingtime = 0;
    p[0].completiontime = p[0].bursttime;
    p[0].turnaroundtime = p[0].bursttime;

    for(int i=1;i<n;i++){
        p[i].waitingtime = p[i-1].waitingtime + p[i-1].bursttime;
        p[i].completiontime = p[i].waitingtime + p[i].bursttime;
        p[i].turnaroundtime = p[i].completiontime;
    }

    float totalwt=0, totaltat=0;

    printf("\nProcess\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].bursttime, p[i].completiontime, p[i].turnaroundtime, p[i].waitingtime);

        totalwt += p[i].waitingtime;
        totaltat += p[i].turnaroundtime;

    }

    printf("Average waiting time is: %.2f\n", totalwt/n);
    printf("Average turnaround time: %.2f", totaltat/n);

    return 0;
}
