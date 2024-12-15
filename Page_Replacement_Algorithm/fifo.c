#include <stdio.h>
#include <stdbool.h>

void fifoPageReplacement(int pages[], int n, int m) {
    int frame[m]; 
    int pageFaults = 0; 
    int index = 0; 

    
    for (int i = 0; i < m; i++) {
        frame[i] = -1;
    }


    for (int i = 0; i < n; i++) {
        bool found = false;


        for (int j = 0; j < m; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }

       
        if (!found) {
            frame[index] = pages[i]; 
            index = (index + 1) % m; 
            pageFaults++; 
        }


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
    int m = 4; 

    fifoPageReplacement(pages, n, m); 

    return 0;
}
