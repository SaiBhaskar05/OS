#include <stdio.h>
#include <stdlib.h> // For abs()

// Function to perform FCFS Disk Scheduling
void fcfs(int req[], int n, int head)
{
    int seek = 0; // Total seek time

    printf("\nFCFS Order: ");
    
    // Traverse through each disk request
    for (int i = 0; i < n; i++)
    {
        printf("%d ", req[i]); // Print the request being served

        // Add the distance moved by the head
        seek += abs(req[i] - head);

        // Move the head to the current request position
        head = req[i];
    }

    printf("\nTotal Seek Time: %d\n", seek); // Print the total seek time
}

int main()
{
    int n, head;

    // Input number of disk requests
    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int req[n];

    // Input disk request sequence
    printf("Enter disk request sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    // Input initial head position
    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Call the FCFS function
    fcfs(req, n, head);

    return 0;
}
