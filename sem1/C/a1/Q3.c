#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int positionOfX(int n)
{
    double x = sqrt(n*(n+1)/2);
    if(floor(x) == ceil(x))
    {
        return (int)x;
    }
    return -1;

}
int main()
{
    int n;
    printf("Enter the last room number");
    scanf("%d",&n);
    int pos = positionOfX(n);
    if(pos!=-1)
    printf("%d ", pos);
    else
    printf("No such room exists");
    
}