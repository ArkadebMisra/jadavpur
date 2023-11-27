// 0 1 2 3 4 
// 1 0 3 2 5 

// 0 1 2 3
// 1 0 3 2
#include<stdio.h>



void swapPos(int arr[], int n){

    for(int i=0;i<n-1;i=i+2){
        int temp = arr[i+1];
        arr[i+1] = arr[i];
        arr[i] = temp;
    }
}
void printArray(int arr[], int n){
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
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

	swapPos(arr, n);
    printArray(arr, n);

	return 0;
}