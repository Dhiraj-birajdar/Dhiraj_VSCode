//also repeated in slip no :- 8 , 12 , 18

/*
Q]Write the simulation program to implement demand paging and 
show the page scheduling and total number of page faults for the 
following given page reference string. Give input n as the number of memory frames.
Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8
1) Implement LRU
*/

#include <stdio.h>
struct frmnode
{
    int pno, counter;
} frames[20];
int n;
int page_found(int pno)
{
    int fno;
    for (fno = 0; fno < n; fno++)
    {
        if (frames[fno].pno == pno)
            return fno;
    }
    return -1;
}

int get_free_frame()
{
    int fno;
    for (fno = 0; fno < n; fno++)
    {
        if (frames[fno].pno == -1)
            return (fno);
    }
    return -1;
}

int get_lru_Frame()
{
    int lrufno = 0, fno;
    for (fno = 1; fno < n; fno++)
    {
        if (frames[fno].counter < frames[lrufno].counter)
            lrufno = fno;
    }
    return lrufno;
}

void main()
{
    int p_request[] = {3, 5, 7, 2, 5, 1, 2, 3, 1, 3, 5, 3, 1, 6, 2};
    int size = sizeof(p_request)/sizeof(p_request[0]);
    int currtime;
    int page_faults = 0, i, j, fno;

    printf("\nHow many frames:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        frames[i].pno = -1;
    }
    printf("\nPageNo Page Frames Page Fault");
    printf("\n---------------------------------------------------");
    currtime = 0;

    //printing table and also counting the page faults
    for (i = 0; i < size; i++)
    {
        j = page_found(p_request[i]);
        if (j == -1)
        {
            j = get_free_frame();
            if (j == -1)
                j = get_lru_Frame();
            page_faults++;
            frames[j].pno = p_request[i];
            frames[j].counter = currtime;
            printf("\n%4d\t ", p_request[i]);
            for (fno = 0; fno < n; fno++)
                printf("%4d:%2d", frames[fno].pno, frames[fno].counter);
            printf(" : YES");
        }
        else
        {
            frames[j].counter = currtime;
            printf("\n%4d\t ", p_request[i]);
            for (fno = 0; fno < n; fno++)
                printf("%4d:%2d", frames[fno].pno, frames[fno].counter);
            printf(" : NO");
        }
        currtime++;
    }
    printf("\n------------------------------------------");
    printf("\nNumber of Page_Faults=%d\n", page_faults);
}
