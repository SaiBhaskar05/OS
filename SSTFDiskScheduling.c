#include <stdio.h>
#include <stdlib.h> // for abs()

int main() {
    int req[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(req) / sizeof(req[0]);
    int head = 53;
    int seek = 0;
    int visited[n];

    // Initially mark all requests as unvisited
    for (int i = 0; i < n; i++) 
        visited[i] = 0;

    printf("\nSSTF Order: ");

    // Process each request
    for (int i = 0; i < n; i++) {
        int idx = -1;
        int min = 1000000000; // large value initially

        // Find the closest unvisited request
        for (int j = 0; j < n; j++) {
            if (!visited[j] && abs(head - req[j]) < min) {
                min = abs(head - req[j]);
                idx = j;
            }
        }

        // Visit the closest request
        visited[idx] = 1;
        printf("%d ", req[idx]);
        
        // Calculate seek time
        seek += abs(req[idx] - head);
        
        // Move head to the current request
        head = req[idx];
    }

    printf("\nTotal Seek Time: %d\n", seek);

    return 0;
}
