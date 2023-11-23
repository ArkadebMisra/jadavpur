// 0 1 2 3 4 5
// 1 0 3 2 5 4

// 0 1 2 3
// 1 0 3 2
#include<stdio.h>



void swapPos(int arr[], int n){

    int in[100];
    int j=0;
    for(int i=1;i<n;i=i+2){
        in[j] = arr[i];
        // printf("%d %d\n", j, i);
        j+=2;
    }
    j=1;
    for(int i=0;i<n;i=i+2){
        in[j] = arr[i];
        j+=2;
    }

    for(int i=0;i<n;i++){
        arr[i] = in[i];
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