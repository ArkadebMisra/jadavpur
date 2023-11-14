#include<stdio.h>


int gcdE(int , int);
int lcm(int, int);
int lcmn(int[], int);

int main(){
    int a[100];
    int n, ans;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter the numbers\n");
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    ans = lcmn(a, n);
    printf("The LCM of the numbers is %d\n", ans);
}



int gcdE(int a, int b)
{
    if (a == 0)
        return b;
    return gcdE(b % a, a);
}

int lcm(int a, int b){
    return (a*b)/gcdE(a, b);
}

int lcmn(int a[], int n){
    int ans;
    ans = a[0];
    for(int i=0;i<n;i++){
        ans = lcm(ans, a[i]);
    }
    return ans;
}


// Input : {1, 2, 8, 3}
// Output : 24

// Input : {2, 7, 3, 9, 4}
// Output : 252