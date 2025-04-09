#include<stdio.h>
#include<stdlib.h>

void sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int size = 200;
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int n = sizeof(requests)/sizeof(requests[0]);
    int head = 50;
    int seektime = 0;

    sort(requests, n);
    int higher[100], lower[100];
    int h= 0, l=0;

    //separate requests higher and lower than head
    for(int i=0;i<n;i++){
        if(requests[i]>=head){
            higher[h++] = requests[i];
        }
        else{
            lower[l++] = requests[i];
        }
    }

    //go from head to tracks
    printf("CSCAN order: %d", head);
    for(int i=0;i<h;i++){
        seektime += abs(head-higher[i]);
        head = higher[i];
        printf(" -> %d", head);
    }

    //go to end and wrap to 0
    if(head!=size-1){
        seektime+=abs(head-(size-1));
        head = 0;
        seektime += (size-1);
        printf("->%d->%d", size-1, head);
    }

    for(int i=0;i<l;i++){
        seektime += abs(head-lower[i]);
        head = lower[i];
        printf(" -> %d", head);
    }

    printf("Total seek time:%d", seektime);
    return 0;
}