#include <stdio.h>

int power(int, int);

int main(){
    int n, p;
    int ans;

    printf("Enter the number\n");
    scanf("%d", &n);
    printf("Enter the power\n");
    scanf("%d", &p);

    ans = power(n, p);

    printf("%d raised to the power %d is %d\n", n, p, ans);
    return 0;
}


int power(int n, int p){
    int ans = 1;
    while(p--){
        ans *= n;
    }
    return ans;
}