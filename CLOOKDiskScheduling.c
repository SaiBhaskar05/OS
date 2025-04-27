#include<stdio.h>
#include<stdlib.h>

int main() {
    int req[] = {82, 170, 43, 140, 24, 16, 190};  // Request array
    int n = sizeof(req) / sizeof(req[0]);        // Number of requests
    int head = 50;                               // Initial position of the head

    // Sorting the request array in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (req[j] > req[j + 1]) {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    int idx = -1;
    // Find the first request greater than or equal to the head
    for (int i = 0; i < n; i++) {
        if (req[i] >= head) {
            idx = i;
            break;
        }
    }

    int seek = 0;

    // Move towards the higher values first (from head to max)
    for (int i = idx; i < n; i++) {
        seek += abs(head - req[i]);
        head = req[i];
    }

    // After reaching the last request, jump to the first request
    // Move towards the higher values (from min to head)
    seek += abs(head - req[0]);
    head = req[0];

    // Continue moving towards higher values
    for (int i = 1; i < idx; i++) {
        seek += abs(head - req[i]);
        head = req[i];
    }

    printf("Total Seek Distance (C-LOOK) = %d\n", seek);
    return 0;
}
