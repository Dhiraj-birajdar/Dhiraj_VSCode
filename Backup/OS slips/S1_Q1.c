//also repeated in slip no :- 11

/*Q] 
write the simulation program to implement demand paging and show the page 
scheduling and total number of page faults according to the LFU page replacement 
algorithm. Assume the memory of n frames. 
reference string : 3,4,5,4,3,4,7,2,4,5,6,7,2,4,6
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_FRAMES 10

typedef struct {
    int page;
    int frequency;
} PageEntry;

int findLFUPage(PageEntry pageTable[], int numFrames) {
    int minFreq = INT_MAX;
    int lfuPageIndex = -1;
    
    for (int i = 0; i < numFrames; ++i) {
        if (pageTable[i].frequency < minFreq) {
            minFreq = pageTable[i].frequency;
            lfuPageIndex = i;
        }
    }
    
    return lfuPageIndex;
}

int LFU(int referenceString[], int numPages, int numFrames) {
    PageEntry pageTable[MAX_FRAMES];
    int pageFaults = 0;
    
    for (int i = 0; i < numFrames; ++i) {
        pageTable[i].page = -1;
        pageTable[i].frequency = 0;
    }
    
    for (int i = 0; i < numPages; ++i) {
        int page = referenceString[i];
        int pageFound = 0;
        
        // Check if the page is already in memory
        for (int j = 0; j < numFrames; ++j) {
            if (pageTable[j].page == page) {
                pageTable[j].frequency++;
                pageFound = 1;
                break;
            }
        }
        
        // If page is not in memory, handle page fault
        if (!pageFound) {
            pageFaults++;
            int lfuPageIndex = findLFUPage(pageTable, numFrames);
            pageTable[lfuPageIndex].page = page;
            pageTable[lfuPageIndex].frequency = 1;
        }
    }
    
    return pageFaults;
}

int main() {
    int referenceString[] = {3, 4, 5, 4, 3, 4, 7, 2, 4, 5, 6, 7, 2, 4, 6};
    int numPages = sizeof(referenceString) / sizeof(referenceString[0]);
    int numFrames = 3;
    
    int totalPageFaults = LFU(referenceString, numPages, numFrames);
    
    printf("Page Scheduling (LFU): ");
    for (int i = 0; i < numPages; ++i) {
        printf("%d ", referenceString[i]);
    }
    printf("\n");
    
    printf("Total number of page faults using LFU algorithm: %d\n", totalPageFaults);
    
    return 0;
}
