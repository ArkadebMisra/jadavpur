#include<stdio.h>
#include <math.h>
#include<float.h>

double sin(double);
double cos(double);
double fact(int);
double xpow(int);

int f = 1;
double f_val = 1;


double r;
int p = 1;
double p_val;

int main(){
    double d;
    double x;
    printf("Enter the degrees: ");
    scanf("%lf", &d);
    x = (3.1415926535897931*d)/180.0; //To calculate the rad

    p_val = x;
    r = x;
    double s = sin(x);
    printf("%lf\n", s);

    p_val = x;
    p = 1;
    f = 1;
    f_val = 1;
    double c = cos(x);
    printf("%lf\n", c);

    return 0;
}

double sin(double x){
    double accuracy = 0.0001;
    double old_sinx = DBL_MAX;
    double new_sinx = x;
    int i=1;
    // printf("%lf", old_sinx-new_sinx);
    while(accuracy < fabs(old_sinx-new_sinx)){
        old_sinx = new_sinx;
        int sign = 1;
        if(i%2==1){
            sign = -1;
        }
        else{
            sign = 1;
        }

        f_val = fact(2*i+1);
        p_val = xpow(2*i+1);
        // printf("f val %lf\n", f_val);
        // printf("p val %lf\n", p_val);


        new_sinx += (sign*p_val)/f_val;
        // printf("%lf\n",new_sinx);
        i++;
    }
    return new_sinx;
}

double cos(double x){
    double accuracy = 0.0001;
    double old_cosx = DBL_MAX;
    double new_cosx = 1;
    int i=1;
    // printf("%lf", old_sinx-new_sinx);
    while(accuracy < fabs(old_cosx-new_cosx)){
        old_cosx = new_cosx;
        int sign = 1;
        if(i%2==1){
            sign = -1;
        }
        else{
            sign = 1;
        }

        f_val = fact(2*i);
        p_val = xpow(2*i);
        // printf("f val %lf\n", f_val);
        // printf("p val %lf\n", p_val);


        new_cosx += (sign*p_val)/f_val;
        // printf("%lf\n",new_sinx);
        i++;
    }
    return new_cosx;
}

double fact(int n){
    for(int i=f+1; i<=n;i++){
        f_val *= i;
    }
    f = n;
    return f_val;
}

double xpow(int n){
    for(int i=p+1; i<=n;i++){
        p_val *= r;
    }
    p = n;
    return p_val;
}