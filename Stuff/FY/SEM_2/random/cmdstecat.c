// #include <stdio.h>
// #include <string.h>

// int main(int argc,char *argv[])
// {
//     // char str[100];
//     // // strcat(argv[1],argv[2]);
//     // strcpy(str,strcat(argv[1],argv[2]));
//     // printf("from str : %s\n%d",str,strlen(str));
//     // printf("from cmd : %s\n",strcat(argv[1],argv[2]));
//     // return 0;
//     FILE *fp;
//     fp=fopen("odd.txt","w+");
//     if (fp==NULL)
//     {
//         printf("cant open");
//     }
//     for (int i = 1; i <=50; i++)
//     {
//         if (i%2!=0)
//         {
//             fprintf(fp,"%d ",i);
//         }
        
//     }
//     char n=fgetc(fp);
//     // printf("\n%d\t%d",n,getw(fp));
//     while (n!=EOF)
//     {
//         // fscanf(fp,"%d",&n);
//         printf("%c\n",n);
//         n=fgetc(fp);
//         // fp++;
//     }
    
// }

#include <stdio.h>
typedef struct book_bank
{
    int book_id;
    char book_name[50];
    char auther[50];
    float price;
}book;

int main()
{
    int n;
    printf("enter no of records \n");
    scanf("%d",&n);
    book rec[n];
    for (int i = 0; i < n; i++)
    {
        printf("entr price\n");
        scanf("%f",&rec[i].price);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     if(rec[i].price>=500 && rec[i].price<=1000)
    //     {
    //         printf("**** %f\n",rec[i].price);
    //     }
    //     // printf("entr price\n");
    //     // scanf("%d",&rec[i].price);
    // }
    int s=0;
    for (int i = 1; i < n; i++)
    {
        if(rec[i].price>rec[s].price)
        {
            s=i;
        }
        // printf("entr price\n");
        // scanf("%d",&rec[i].price);
    }
            printf("highest price %f\n",rec[s].price);
    
    return 0;
}