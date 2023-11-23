#include <stdio.h>
#include<math.h>
int main()

{

    float x, i, sum, log_sum;
    printf("Enter the value of x : ");
    scanf("%f",&x);
    sum=0;
    for (i=2; i<=20; i++)
    {
         sum=sum+((1/i)*pow(((x-1)/x), i));
    }
    log_sum=((x-1)/x)+sum;
    printf("\nSum of log series is %f\n",log_sum);

    return 0;
}