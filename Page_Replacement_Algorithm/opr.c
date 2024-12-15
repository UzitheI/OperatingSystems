#include <stdio.h>
#include <stdbool.h>

int findOptimalPage(int pages[], int n, int frame[], int m, int index) {
    int farthest = index;
    int pageIndex = -1;

    for (int i = 0; i < m; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pageIndex = i;
                }
                break;
            }
        }

        // If the page is not found in the future references
        if (j == n) {
            return i;
        }
    }

    // If all pages are found in the future, return the page with the farthest reference
    return (pageIndex == -1) ? 0 : pageIndex;
}

void optimalPageReplacement(int pages[], int n, int m) {
    int frame[m];
    int pageFaults = 0;

    // Initialize frames as empty
    for (int i = 0; i < m; i++) {
        frame[i] = -1;
    }

    // Iterate over the pages
    for (int i = 0; i < n; i++) {
        bool found = false;

        // Check if the page is already in a frame
        for (int j = 0; j < m; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }

        // If the page is not found, replace it
        if (!found) {
            pageFaults++;

            // If there is an empty frame, use it
            bool emptyFound = false;
            for (int j = 0; j < m; j++) {
                if (frame[j] == -1) {
                    frame[j] = pages[i];
                    emptyFound = true;
                    break;
                }
            }

            // If no empty frame is found, replace the optimal page
            if (!emptyFound) {
                int optimalIndex = findOptimalPage(pages, n, frame, m, i + 1);
                frame[optimalIndex] = pages[i];
            }
        }

        // Print the current state of the frames
        printf("\nFrame state after accessing page %d: ", pages[i]);
        for (int j = 0; j < m; j++) {
            if (frame[j] != -1) {
                printf("%d ", frame[j]);
            } else {
                printf("- ");
            }
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int m = 4;  // Number of frames

    optimalPageReplacement(pages, n, m);

    return 0;
}
