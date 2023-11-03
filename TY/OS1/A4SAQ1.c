//Q4 write the simulation program in c to implement demand paging and show the page scheduling and total number of page faults for the following given page reference string. 
// give input n as the number of memory frames. 
// reference string :  12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8 (implement fifo an lru)
#include <stdio.h>
#include <stdbool.h>

// Function to find if a page is in memory
bool isInMemory(int page, int memory[], int n) {
    for (int i = 0; i < n; i++) {
        if (memory[i] == page) {
            return true;
        }
    }
    return false;
}

// Implement FIFO page replacement algorithm
int fifoPageReplacement(int pages[], int n, int num_frames) {
    int memory[num_frames];
    int page_faults = 0;
    int frame_index = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        if (!isInMemory(page, memory, num_frames)) {
            memory[frame_index] = page;
            frame_index = (frame_index + 1) % num_frames;
            page_faults++;
        }
    }
    return page_faults;
}

// Implement LRU page replacement algorithm
int lruPageReplacement(int pages[], int n, int num_frames) {
    int memory[num_frames];
    int page_faults = 0;
    int page_index[num_frames];

    for (int i = 0; i < num_frames; i++) {
        memory[i] = -1;
        page_index[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int j;
        for (j = 0; j < num_frames; j++) {
            if (memory[j] == page) {
                page_index[j] = i;
                break;
            }
        }
        if (j == num_frames) {
            int least_recently_used = 0;
            for (int k = 1; k < num_frames; k++) {
                if (page_index[k] < page_index[least_recently_used]) {
                    least_recently_used = k;
                }
            }
            memory[least_recently_used] = page;
            page_index[least_recently_used] = i;
            page_faults++;
        }
    }
    return page_faults;
}

int main() {
    int refs[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
    int num_pages = sizeof(refs) / sizeof(refs[0]);
    int num_frames;

    printf("Enter the number of memory frames: ");
    scanf("%d", &num_frames);

    int fifopf = fifoPageReplacement(refs, num_pages, num_frames);
    int lrupf = lruPageReplacement(refs, num_pages, num_frames);

    printf("FIFO Page Faults: %d\n", fifopf);
    printf("LRU Page Faults: %d\n", lrupf);

    return 0;
}
