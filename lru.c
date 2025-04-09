#include <stdio.h>

void lru(int pages[], int n, int frameSize) {
    int frames[frameSize], time[frameSize];
    int count = 0, faults = 0;
    int flag1, flag2, pos, i, j;

    for(i = 0; i < frameSize; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        flag1 = flag2 = 0;

        // Check if page already in frame
        for(j = 0; j < frameSize; j++) {
            if(frames[j] == pages[i]) {
                count++;
                time[j] = count;
                flag1 = flag2 = 1;
                break;
            }
        }

        // Page not found and space available
        if(flag1 == 0) {
            for(j = 0; j < frameSize; j++) {
                if(frames[j] == -1) {
                    count++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = count;
                    flag2 = 1;
                    break;
                }
            }
        }

        // Replace least recently used page
        if(flag2 == 0) {
            int minTime = time[0];
            pos = 0;
            for(j = 1; j < frameSize; j++) {
                if(time[j] < minTime) {
                    minTime = time[j];
                    pos = j;
                }
            }
            count++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = count;
        }
    }

    printf("Total Page Faults (LRU) = %d\n", faults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frameSize = 3;

    printf("Page Reference String: ");
    for(int i = 0; i < n; i++) printf("%d ", pages[i]);
    printf("\n");

    lru(pages, n, frameSize);

    return 0;
}