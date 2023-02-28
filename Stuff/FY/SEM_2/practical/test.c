// #include <stdio.h>

// void main()
// {
//     FILE *fp;
//     int num = 1555, n;
//     fp = fopen("demo.txt", "w");

//     putw(12225,fp);
//     putw(num,fp);

//     fclose(fp);
// }

#include <stdio.h>
#include <string.h>
void main()
{
  char s[100], c, *p;
  printf("Enter a string : ");
  gets(s);
  printf("\nEnter a character : ");
  scanf("%c", &c);
  p = strchr(s, c);
  if (p == NULL)
    printf("\ncharacter '%c' is not present in string '%s'", c, s);
  else
    printf("\ncharacter '%c' is present in string '%s'", c, s);
}