#include <stdio.h>

int main() {
    int frames, pages[100], n, frame[10], i, faults = 0;

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
                break;
            }
        }

        // If not found, replace page based on future use
        if (!found) {
            int replace = -1, farthest = i + 1;

            // Find the frame whose page is used farthest in future
            for (int k = 0; k < frames; k++) {
                int j;
                for (j = i + 1; j < n; j++)
                    if (frame[k] == pages[j]) break;
                if (j > farthest) {
                    farthest = j;
                    replace = k;
                }
            }

            // If no page will be used again, replace first frame
            if (replace == -1)
                replace = 0;
                
            frame[replace] = pages[i]; // Replace the selected frame
            faults++; // Increase page fault count
        }
    }

    // Output total page faults
    printf("Page Faults = %d\n", faults);
    return 0;
}

----------------sample output------------------------
Enter number of pages: 12
Enter page sequence: 1 3 0 3 5 6 3 0 1 5 6 2
Enter number of frames: 3
Page Faults = 7
