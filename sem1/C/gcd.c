#include<stdio.h>
#include<stdlib.h>


void primeFactors(int n, int[]);
int gcdE(int , int);
int gcd(int, int);
int power(int , int);

int main(){
    int a, b, ans;
    printf("Enter two numbers to find their GCD\n");
    scanf("%d", &a);
    scanf("%d", &b);
    ans = gcdE(a, b);
    printf("GCD using euclids algo - %d\n", ans);

    ans = gcd(a, b);
    printf("GCD using prime factorization - %d\n", ans);
    return 0;
}


void primeFactors(int n, int factors[]) 
{ 
    // Print the number of 2s that divide n
    // printf("here\n");
    int k=1; 
    while (n%2 == 0) 
    { 
        // printf("%d ", 2);
        factors[2]++;
        n = n/2; 
    } 
  
//   printf("\n-------%d----\n", factors[1]);
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (int i = 3; i*i <= n; i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            // printf("%d ", i);
            factors[i]++;
            n = n/i; 
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2)
        factors[n]++; 
        // printf ("%d ", n); 

}

int gcd(int a, int b){
    // int sz = a<b?(a+1):(b+1);
    int *arrA = (int *)calloc(a+1, sizeof(int));
    int *arrB = (int *)calloc(b+1, sizeof(int));
    int n= a<b?a:b;
    // printf("n----------%d", n);
    primeFactors(a,arrA);
    primeFactors(b,arrB);

    int ans = 1;
    int i=1;
    while(i<=n){
        // printf("%d", arr[i]);
        if(arrA[i]!=0 && arrB[i]!=0){
            int p = arrA[i]<arrB[i]?arrA[i]:arrB[i];
            ans*= power(i, p);
        }
        i++;
    }
    return ans;
}


int gcdE(int a, int b)
{
    if (a == 0)
        return b;
    return gcdE(b % a, a);
}

int power(int n, int p){
    int ans = 1;
    while(p--){
        ans *= n;
    }
    return ans;
}

//36 60, 45 30, 24 30