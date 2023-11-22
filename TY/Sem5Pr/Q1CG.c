#include <stdio.h>

#define MAX_FRAMES 10

void fifoAlgorithm(int referenceString[], int numPages, int numFrames)
{
    int pageTable[MAX_FRAMES];
    int pageFaults = 0;
    int currentIndex = 0;

    for (int i = 0; i < numFrames; i++) {
        pageTable[i] = -1;  // Initialize page table with -1 (indicating empty frames)
    }

    for (int i = 0; i < numPages; i++) {
        int currentPage = referenceString[i];
        int pageFound = 0;

        // Check if the page is already in the page table
        for (int j = 0; j < numFrames; j++) {
            if (pageTable[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }

        // If the page is not in the page table, handle page fault
        if (!pageFound) {
            // Replace the oldest page with the current page
            pageTable[currentIndex] = currentPage;
            currentIndex = (currentIndex + 1) % numFrames;
            pageFaults++;

            // Display the current page table
            printf("Page Table: ");
            for (int j = 0; j < numFrames; j++) {
                printf("%d ", pageTable[j]);
            }
            printf("\n");
        }
    }

    printf("Total Number of Page Faults: %d\n", pageFaults);
}

int main() 
{
    // Define the reference string and the number of frames
    int referenceString[] = {1,1,1,2};
    int numPages = sizeof(referenceString) / sizeof(referenceString[0]);
    int numFrames = 3;

    // Run the simulation
    printf("Simulation using FIFO Page Replacement Algorithm:\n");
    fifoAlgorithm(referenceString, numPages, numFrames);

    return 0;
}
