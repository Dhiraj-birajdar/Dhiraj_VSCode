#include <stdio.h>

int pageFaults(int ref[], int n, int f)
{
    int frame[f];
    int empty = f-1;
    int pagefaults = 0;
    int first = -1,last = -1;
    for(int i = 0; i<n; i++)
    {
        if(first == -1)
        {
            pagefaults++;
            frame[++first] = ref[i];
            empty--;
            last++;
        }
        else
        {
            for(int j=0; j<f; j++)
            {
                if(ref[i] == frame[j])
                    break;
                if(j== f-1)
                {
                    pagefaults++;
                    if(empty >= 0)
                    {
                        empty--;
                        last = (last+1)%3;
                        frame[last] = ref[i];
                    }
                    else
                    {
                        frame[first] = ref[i];
                        first = (first+1)%3;
                    }
                }
            }
        }
    }
    return pagefaults;
}

int main()
{
    int ref[] = {1,2,3,4,5};
    int frames = 4;
    printf("page faults = %d",pageFaults(ref, 5, frames));
    return 0;
}