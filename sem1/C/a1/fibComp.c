#include<stdio.h>
#include<math.h>


double fib(int);

double closedFib(int);

int main(){
    int n;
    double f, fc;
    printf("Enter the number\n");
    scanf("%d", &n);

    f = fib(n);
    fc = closedFib(n);
    printf("fibonacci with recursive formula  %lf\n", f);
    printf("fibonacci with closed form formula  %lf\n", fc);
    printf("%lf\n", fabs(f-fc));
    return 0;

}

double fib(int n){
    double a[2], temp;
    a[0] = 0;
    a[1] = 1;

    if(n<=1){
        return a[n];
    }
    for(int i=2;i<=n;i++){
        temp = a[0]+a[1];
        a[0] = a[1];
        a[1] = temp;
    }
    return a[1];
}


double closedFib(int n){
    double f = (double)n;

    double one_by_rt_five = 1.0/sqrt(5.0);
    double fib = one_by_rt_five*pow(((1.0+sqrt(5.0))/2), f) - one_by_rt_five*pow(((1.0-sqrt(5.0))/2), f);
    return fib;
}