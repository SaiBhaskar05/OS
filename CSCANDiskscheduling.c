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

    // Find the index where the head should be placed
    int idx = -1;
    for(int i = 0; i < n; i++) {
        if (req[i] >= head) {
            idx = i;
            break;
        }
    }

    // Start calculating seek time
    int seek = 0;

    // First, move left (towards the smallest request)
    for (int i = idx - 1; i >= 0; i--) {
        seek += abs(head - req[i]);
        head = req[i];
    }

    // After reaching the leftmost request, jump to the largest request (size - 1)
    seek += abs(head - 0); // Move to the farthest point (0)
    head = 0;

    // Now, move from 0 to the right (towards the largest request)
    for (int i = idx; i < n; i++) {
        seek += abs(head - req[i]);
        head = req[i];
    }

    // Output the total seek time
    printf("\nTotal Seek Time (C-SCAN, Left First): %d\n", seek);

    return 0;
}
