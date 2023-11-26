//also repeated in slip no :- 9 , 10 

/*
Q] write the simulation program for damand paging and show the 
page scheduling and total number pf page faults according to the
FIFO page replacement algo. Assume the memory of n frames.
Reference string : 3,4,5,6,3,4,7,3,4,5,6,7,2,4,6
*/
#include <stdio.h>
struct frmnode
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
    return (-1);
}

int get_fifo_frame()
{
    static int fno = -1;
    fno = (fno + 1) % n;
    return fno;
}

void main()
{
    int p_request[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int size = sizeof(p_request) / sizeof(int);
    printf("%d", size);
    int page_falts = 0, i, j, fno;

    printf("\nHow many frames:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        frames[i].pno = -1;
    }
    printf("\nPageNo Page Frames Page Fault");
    printf("\n---------------------------------------------------");
    for (i = 0; i < size; i++)
    {
        j = page_found(p_request[i]);
        if (j == -1)
        {
            page_falts++;
            j = get_free_frame();
            if (j == -1)
                j = get_fifo_frame();
            frames[j].pno = p_request[i];
            printf("\n%4d\t ", p_request[i]);
            for (fno = 0; fno < n; fno++)
                printf("%4d", frames[fno].pno);
            printf(" : YES");
        }
        else
        {
            printf("\n%4d\t ", p_request[i]);
            for (fno = 0; fno < n; fno++)
                printf("%4d", frames[fno].pno);
            printf(" : NO");
        }
    }
    printf("\n-------------------------------------------------------");
    printf("\n Number of Page_Falts=%d", page_falts);
}
