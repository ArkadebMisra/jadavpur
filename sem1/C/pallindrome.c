#include <stdio.h>

int reverse(int);

int main(){
    int n;
    printf("Enter the number\n");
    scanf("%d", &n);
    int p = reverse(n);
    if(n==p){
        printf("The number is a pallindrome\n");
    }
    return 0;
}

int reverse(int n){
    int ans = 0;
    while(n!=0){
        ans = (ans*10)+(n%10);
        n /=10;
    }
    printf("The reversed number is %d\n", ans);
    return ans;
}