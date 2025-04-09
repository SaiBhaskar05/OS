#include<stdio.h>

struct process{
    int id;
    int burst;
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
        printf("Enter burst time for process %d: ", p[i].id);
        scanf("%d", &p[i].burst);
    }

    //sorting by burst time(sjf)

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].burst>p[j+1].burst){
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    int time=0;
    float totalwt = 0, totaltat = 0;

    for(int i=0;i<n;i++){
        time+=p[i].burst;
        p[i].completion = time;
        p[i].turnaround = p[i].completion;
        p[i].waiting = p[i].turnaround - p[i].burst;

        totalwt += p[i].waiting;
        totaltat += p[i].turnaround;
    }

    printf("\nP\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].burst, p[i].completion, p[i].turnaround, p[i].waiting);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalwt / n);
    printf("Average Turnaround Time: %.2f\n", totaltat / n);

    return 0;
}