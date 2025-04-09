#include <stdio.h>
#include <stdlib.h>

int absDiff(int a, int b) {
    return (a > b) ? a - b : b - a;
}

int main() {
    int request[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(request)/sizeof(request[0]);
    int head = 53;
    int totalSeek = 0;
    int done[100] = {0};

    printf("Initial head position: %d\n", head);

    for (int i = 0; i < n; i++) {
        int min = 100000, pos = -1;
        for (int j = 0; j < n; j++) {
            if (!done[j]) {
                int diff = absDiff(request[j], head);
                if (diff < min) {
                    min = diff;
                    pos = j;
                }
            }
        }
        totalSeek += absDiff(request[pos], head);
        head = request[pos];
        done[pos] = 1;
        printf("Moved to: %d\n", head);
    }

    printf("Total Seek Time (SSTF): %d\n", totalSeek);
    return 0;
}
