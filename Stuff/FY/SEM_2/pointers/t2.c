#include <stdio.h>
#include <string.h>
// int main(int argc, char *argv[])
int main()
{
    //     //     int a[4][4]={1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
    //     //     // int a[]={1,2,3,4};
    //     //     int i=1,j=1;
    //     // printf("%d\n",a[i][j]);
    //     // printf("%d\n",*(*(a+2)+3));
    //     // printf("%d\n",(*(a+1))+1);

    // //! <===================assignment================>
    // // * count the no of words from uses accepted string
    // char a[] = "my name DHIraj biraj hi e amd ca d", b[] = "DHI.RAJ";
    char a[200];
    int i = 0, wc = 0;
    printf("Enter string : \n");
    gets(a);
    while (a[i++] != '\0')
    {
        // if (a[i] == ' ' && a[i+1] != ' ' || i== strlen(a)-1)
        if (a[i] == ' ' && a[i+1] != ' ')
        {
            wc++;
        }
        // i++;
    }
    // printf("no of words are %d\n", wc);
    printf("no of words are %d\n", wc+1);
    // //! <=============================================>

    //     // r=strncmp(a,b,3);
    //     // printf("a and b %d\n",r);
    //     // printf("no of arguments %d\n",argc);
    //     // printf("argv[0] = %s\n",argv[0]);
    //     // printf("argv[1] = %s\n",argv[1]);
    //     return 0;
    //     char s[200];
    int count = 0;

    // printf("Enter the string:\n");
    // gets(s);
    for (i = 0;a[i] != '\0';i++)
    {
        if (a[i] == ' ' || a[i]=='\n' || a[i]=='\t')
            count++;
    }
    printf("Number of words in given string are: %d\n", count + 1);
}

// #include <stdio.h>
// #include <string.h>

// void main()
// {
//     char s[200];
//     int count = 0, i;

//     printf("Enter the string:\n");
//     gets(s);
//     for (i = 0;s[i] != '\0';i++)
//     {
//         if (s[i] == ' ' && s[i+1] != ' ')
//             count++;
//     }
//     printf("Number of words in given string are: %d\n", count + 1);
// }