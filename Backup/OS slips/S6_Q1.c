//also repeated in slip no :- never repeated

/*
Write the simulation program to implement demand paging and show the page
scheduling and total number of page faults for the following given page reference string.
Give input n as the number of memory frames.
Reference String :- 8,5,7,8,5,7,2,3,7,3,5,9,4,6,2

1) Implement MRU
*/

#include <stdio.h>

struct framenode
{
    int pno;
    int counter;
} frames[20];

int n;

int page_found(int pno)
{
    int fno;
    for (fno = 0; fno < n; fno++)
    {
        if (frames[fno].pno == pno)
            return fno; // returns the index of the frame if the page is found in the frame
    }
    return -1; // if not then return -1
}

int get_free_frame()
{
    int fno;
    for (fno = 0; fno < n; fno++)
    {
        if (frames[fno].pno == -1)
            return (fno); // returns the index of the free frame if found
    }
    return -1; // if not then return -1
}

int get_mru_frame()
{
    int mrufno = 0, fno;
    for (fno = 1; fno < n; fno++)
    {
        if (frames[fno].counter > frames[mrufno].counter)
            mrufno = fno;
    }
    return mrufno;
}

void main()
{
    int p_request[] = {8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2};
    int size = sizeof(p_request) / sizeof(p_request[0]); // store total no of p_request in variable size (15)
    int page_faults = 0;
    int currtime;
    int i, j, fno;
    printf("%d", size);

    printf("\nHow many frames:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        frames[i].pno = -1; // iterate over frames and set them (initialize) as -1
    }
    printf("\nPageNo Page Frames Page Fault");
    printf("\n---------------------------------------------------");
    currtime = 0;
    
    //printing table and also counting the page faults
    for (i = 0; i < size; i++)
    {
        j = page_found(p_request[i]); // returns current frame index if not found (in da memory) returns -1
        if (j == -1)                  // if page fault occures(not found in da memory cykaa) increase the counter
        {
           // page_faults++;

            j = get_free_frame(); // finds free frame in the memory

            if (j == -1)                               // if frame not found (available) then find the opt frame
                j = get_mru_frame(); // function call (finds mru frame)

            page_faults++;
            frames[j].pno = p_request[i]; // load or replace the current page in selected frame
           frames[j].counter = currtime; //changes here (keeping the couter of each page in a frame)
            printf("\n%4d\t ", p_request[i]);
            for (fno = 0; fno < n; fno++)
                printf("%4d : %2d", frames[fno].pno , frames[fno].counter);
            printf(" : YES"); // page fault
        }
        else
        {
            frames[j].counter = currtime;  //changes here (keeping the couter of each page in a frame)
            printf("\n%4d\t ", p_request[i]);
            for (fno = 0; fno < n; fno++)
                printf("%4d : %2d", frames[fno].pno , frames[fno].counter);
            printf(" : NO"); // no page fault
        }
        currtime++;
    }
    printf("\n-------------------------------------------------------");
    printf("\n Number of Page_Falts=%d", page_faults);
}