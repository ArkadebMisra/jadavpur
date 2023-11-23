#include <stdio.h>
#include <limits.h>

int minArr(int arr[], int n){
    int min = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}


int maxArr(int arr[], int n){
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

	printf("The minimum element of the array is %d\n", minArr(arr, n));
	printf("The maximum element of the array is %d\n", maxArr(arr, n));

	return 0;
}