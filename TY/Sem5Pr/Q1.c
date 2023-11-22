/*
Q.1 Write the simulation program for demand paging and show the page 
 scheduling and total number of page faults according the FIFO page 
 replacement algorithm. Assume the memory of n frames.
Reference String : 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2
*/

#include <stdio.h>

int FIFO(int ref[], int n, int f)
{
    int frames[f];
    int current = 1;
    int pagefaults = 0;
    int i;

    for(i=0;i<f;i++)
        frames[i] = -1;

    for(i = 0;i<n;i++)
    {
        int cpage = ref[i];
        int pagefound = 0;

        for(int j = 0;j<f;j++)
        {
            if(cpage == frames[j])
            {
                pagefound = 1;
                break;
            }
        }

        if(!pagefound)
        {
            frames[current] = cpage;
            current = (current+1)%f;
            pagefaults++;
        }
    }
    return pagefaults;

}

int main()
{
    int ref[] = {1,2,3,4,3,2,1,4,5};
    int pages = 9;
    int frames = 4;

    printf("Page Faults using FIFO : %d", FIFO(ref,pages,frames));
    return 0;
}