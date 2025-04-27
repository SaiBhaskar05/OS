#include<stdio.h>
#include<stdlib.h>

struct process {
    int id;
    int at; // arrival time
    int bt; // burst time
    int rt; // remaining time
    int wt; // waiting time
    int tat; // turn around time
    int ct; // completion time
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    for(int i=0; i<n; i++) {
        p[i].id = i+1;
        printf("Enter arrival time for process %d: ", p[i].id);
        scanf("%d", &p[i].at);
        printf("Enter burst time for process %d: ", p[i].id);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt; // initially remaining time is full burst time
    }

    int completed = 0, time = 0, min_rt = 9999, shortest = -1;
    float total_wt = 0, total_tat = 0;
    int finish_time;

    while(completed != n) {
        shortest = -1;
        min_rt = 9999;

        for(int i=0; i<n; i++) {
            if(p[i].at <= time && p[i].rt > 0 && p[i].rt < min_rt) {
                min_rt = p[i].rt;
                shortest = i;
            }
        }

        if(shortest == -1) {
            time++; // if no process is ready, just move time
            continue;
        }

        p[shortest].rt--; // run process for 1 unit

        if(p[shortest].rt == 0) {
            completed++;
            finish_time = time + 1;
            p[shortest].ct = finish_time;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;

            total_wt += p[shortest].wt;
            total_tat += p[shortest].tat;
        }

        time++;
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt/n);
    printf("Average Turn Around Time = %.2f\n", total_tat/n);

    return 0;
}
