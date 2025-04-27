#include<stdio.h>
#include<stdlib.h>

int main() {
    int req[] = {82, 170, 43, 140, 24, 16, 190};
    int n = sizeof(req) / sizeof(req[0]);
    int head = 50;
    int size = 200; // Max cylinder number

    // Sort the request array
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
    printf("\nSCAN Order: ");

    int idx = 0;
    // Find where the head position would be inserted
    for (int i = 0; i < n; i++) {
        if (req[i] >= head) {
            idx = i;
            break;
        }
    }

    // Move toward left first (toward 0)
    for (int i = idx-1; i >= 0; i--) {
        printf("%d ", req[i]);
        seek += abs(head - req[i]);
        head = req[i];
    }

    // Move to 0 if not already at 0
    if (head != 0) {
        seek += head; // Move from current head to 0
        head = 0;
    }

    // Then move right
    for (int i = idx; i < n; i++) {
        printf("%d ", req[i]);
        seek += abs(head - req[i]);
        head = req[i];
    }

    printf("\nTotal Seek Time: %d\n", seek);

    return 0;
}
