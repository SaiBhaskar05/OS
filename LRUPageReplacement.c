#include <stdio.h>

int main() {
    int frames, pages[100], n, frame[10], i, faults = 0, time[10], counter = 0;

    // Input number of pages
    printf("Enter number of pages: ");
    scanf("%d", &n);

    // Input page sequence
    printf("Enter page sequence: ");
    for (i = 0; i < n; i++) 
        scanf("%d", &pages[i]);

    // Input number of frames
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    // Initialize frames to -1 (empty)
    for (i = 0; i < frames; i++) 
        frame[i] = -1;

    // Process each page
    for (i = 0; i < n; i++) {
        int found = 0;

        // Check if page is already in a frame
        for (int k = 0; k < frames; k++) {
            if (frame[k] == pages[i]) {
                found = 1;
                time[k] = ++counter; // Update time (recently used)
                break;
            }
        }

        // If not found, replace the least recently used page
        if (!found) {
            int min = 0;
            for (int k = 1; k < frames; k++)
                if (time[k] < time[min]) min = k; // Find least recently used
            frame[min] = pages[i]; // Replace it
            time[min] = ++counter; // Update usage time
            faults++; // Increase page fault count
        }
    }

    // Output total page faults
    printf("Page Faults = %d\n", faults);
    return 0;
}

------------------sample output----------------------
Enter number of pages: 12
Enter page sequence: 1 3 0 3 5 6 3 0 1 5 6 2
Enter number of frames: 3
Page Faults = 8

