#include <stdio.h>

double mean(int arr[], int n){
    double s = 0;
    for(int i=0;i<n;i++){
        s += arr[i];
    }
    return s/(double)n;
}
0 1 2 3 4

int mode(int arr[], int n){
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
    
}

int main()
{
	int arr[100];
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);

    printf("Enter the array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

	printf("The mean of the array is %d\n", mean(arr, n));
	printf("The mode of the array is %d\n", mode(arr, n));
    printf("The mode of the array is %d\n", sd(arr, n));

	return 0;
}