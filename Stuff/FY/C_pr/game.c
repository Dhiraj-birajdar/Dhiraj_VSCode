#include<stdio.h>
#include<stdlib.h>          // 1
#include<time.h>             //2

int main()
{
    int num,guess,nguess=1;
    srand(time(0));            // 3
    num=rand()%100+1;           // 4      generates random no.
   // printf("random no is %d",num);
    
    do{
        printf("**Guess the number between 1 to 100**\n");
        scanf("%d",&guess);
        if (guess>num){
            printf("lower number please !\n");
        }
        else if (guess<num){
            printf("higher number please !\n");
        }
        else{
            printf("you guessed number in %d guesses\n",nguess);
        }nguess++;
    }while (guess!=num);
    
}