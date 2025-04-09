#include<stdio.h>

struct process{
    int id;
    int arrival;
    int burst;
    int start;
    int completion;
    int turnaround;
    int waiting;
};

int main(){
    int n;
    struct process p[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        p[i].id = i+1;
        printf("Enter arrival time and burst time for process %d: ", p[i].id);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].arrival>p[j+1].arrival){
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    int time =0;
    float totalwt = 0, totaltat = 0;

    for(int i=0;i<n;i++){
        if(time<p[i].arrival){
            time = p[i].arrival;//cpu is idle
        }
        p[i].start = time;
        p[i].completion = p[i].start + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        time = p[i].completion;
        totalwt += p[i].waiting;
        totaltat += p[i].turnaround;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].arrival, p[i].burst, p[i].completion, p[i].turnaround, p[i].waiting);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalwt/n);
    printf("Average Turnaround Time: %.2f\n", totaltat/n);
}