#include<stdio.h>

void sieve_of_eratosthenes(int n)
{
    int is_prime[10000];
    for(int i=0;i<n+1;i++){
        is_prime[i] = 1;
    }
    is_prime[0] = is_prime[1] = 0;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
 
int main()
{
    int n;
    printf("Enter the number upto which you want to find prime numbers\n");
    scanf("%d", &n);
    sieve_of_eratosthenes(n);
    return 0;
}