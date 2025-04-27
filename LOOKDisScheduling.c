#include<stdio.h>
#include<stdlib.h>

int main(){
    int req[] = {82, 170, 43, 140, 24, 16, 190};
    int n = sizeof(req) / sizeof(req[0]);
    int head = 50, size = 200;

    // Sort the request array in ascending order
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (req[j] > req[j+1]) {
                int temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }
    }

    int seek = 0;
    int idx = -1;

    // Find the index where the head is located or the nearest larger element
    for(int i = 0; i < n; i++) {
        if (req[i] >= head) {
            idx = i;
            break;
        }
    }

    // Move left (towards lower request values) first
    for(int i = idx-1; i >= 0; i--) {
        seek += abs(head - req[i]);
        head = req[i];
    }

    // Move right (towards higher request values) after completing leftward movement
    for(int i = idx; i < n; i++) {
        seek += abs(head - req[i]);
        head = req[i];
    }

    printf("Total Seek Distance = %d\n", seek);
    return 0;
}
