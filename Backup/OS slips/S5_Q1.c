//also repeated in slip no :- 7 , 17 , 23

/*
Write the simulation program to implement demand paging and show the page 
scheduling and total number of page faults for the following given page reference string. 
Give input n as the number of memory frames.
Reference String : 

1) Implement OPT :- 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2
*/


#include <stdio.h>

struct framenode
{
    int pno;
} frames[20];

int n;

int page_found(int pno)
{
    int fno;
    for (fno = 0; fno < n; fno++)
    {
        if (frames[fno].pno == pno)
            return fno;  //returns the index of the frame if the page is found in the frame
    }
    return -1; //if not then return -1
}

int get_free_frame()
{
    int fno;
    for (fno = 0; fno < n; fno++)
    {
        if (frames[fno].pno == -1)
            return (fno);  //returns the index of the free frame if found
    } 
    return -1;  //if not then return -1
}

int get_opt_frame(int p_request[], int current_page, int size)
{
    int fno = -1;
    int farthest_use = -1;
    for (int i = 0; i < n; i++)
    {
        int future_use = size;
        for (int j = current_page + 1; j < size; j++)
        {
            if (frames[i].pno == p_request[j])
            {
                future_use = j;
                break;
            }
        }
        if (future_use > farthest_use)
        {
            farthest_use = future_use;
            fno = i;   // store the index of the frame with the farthest future use.
        }
    }
    return fno;
}


int main()
{
    int p_request[] = {8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2};
    int size = sizeof(p_request) / sizeof(int);  //store total no of p_request in variable size (15) 
    int page_faults = 0;
    int i, j, fno;
    printf("%d", size);

    printf("\nHow many frames:");
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        frames[i].pno = -1; //iterate over frames and set them (initialize) as -1
    }
    printf("\nPageNo Page Frames Page Fault");
    printf("\n---------------------------------------------------");
    for (i = 0; i < size; i++)
    {
        j = page_found(p_request[i]);  //returns current frame index if not found (in da memory) returns -1
        if (j == -1)  //if page fault occures(not found in da memory cykaa) increase the counter
        {
            page_faults++;
            
            j = get_free_frame();  //finds free frame in the memory
           
            if (j == -1)   //if frame not found (available) then find the opt frame
                j = get_opt_frame(p_request, i, size);  //function call (finds opt frame)
            
            frames[j].pno = p_request[i];  //load or replace the current page in selected frame
            printf("\n%4d\t ", p_request[i]);
            for (fno = 0; fno < n; fno++)
                printf("%4d", frames[fno].pno);
            printf(" : YES"); //page fault 
        }
        else
        {
            printf("\n%4d\t ", p_request[i]);
            for (fno = 0; fno < n; fno++)
                printf("%4d", frames[fno].pno);
            printf(" : NO"); //no page fault
        }
    }
    printf("\n-------------------------------------------------------");
    printf("\n Number of Page_Falts=%d", page_faults);
    return 0;
}