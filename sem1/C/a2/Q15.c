#include<stdio.h>
#define TERMS 10
void pascalTriangle(int);

int main()
{
    printf("Pascal's triangle upto 10 lines : \n");
    pascalTriangle(TERMS);
}

void pascalTriangle(int n){
    int c = 1, blk, i, j;
   for (i = 0; i < n; i++) 
   {
        for (j = 0; j <= i; j++) 
        {
            if (j == 0 || i == 0) 
                c = 1;
            else
                c = c * (i - j + 1) / j; 
            printf("% d", c); 
        }

        printf("\n"); 
    }
}