#include <stdio.h>
int FIFO(int ref[], int n, int f)
{
    int frames[f];
    int current = 0;
    int pagefaults = 0;

    for(int i=0;i<f;i++)
        frames[i] = -1;

    for(int i = 0;i<n;i++)
    {
        int cpage = ref[i];
        int pagefound = 0;

        for(int j = 0;j<f;j++)
            if(cpage == frames[j])
            {
                pagefound = 1;
                break;
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
    int ref[] = {8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2};
    int pages = 15, frames;
    printf("Enter no of Frames : ");
    scanf("%d",&frames);

    printf("Page Faults using FIFO : %d", FIFO(ref,pages,frames));
    return 0;
}