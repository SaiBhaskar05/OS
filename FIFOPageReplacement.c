#include <stdio.h>

int main() {
    int frames, pages[100], n, frame[10], i, j = 0, faults = 0;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page sequence: ");
    for (i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    
    for (i = 0; i < frames; i++) frame[i] = -1;
    
    for (i = 0; i < n; i++) {
        int found = 0;
        for (int k = 0; k < frames; k++) {
            if (frame[k] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            frame[j] = pages[i];
            j = (j + 1) % frames;
            faults++;
        }
    }
    
    printf("Page Faults = %d\n", faults);
    return 0;
}


-------------------sample output-----------------------------------
Enter number of pages: 12
Enter page sequence: 1 3 0 3 5 6 3 0 1 5 6 2
Enter number of frames: 3
Page Faults = 9
