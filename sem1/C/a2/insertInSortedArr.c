#include <stdio.h>

void printArray(int arr[], int n){
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void insertEle(int e, int arr[], int n){
    int index =-1;
    for(int i=0;i<n;i++){
        if(arr[i]>e){
            index=i;
            break;
        }
    }

    if(index==-1){
        arr[n]=e;
    }
    else{
        for(int i=n-1;i>=index;i--){
            arr[i+1] = arr[i];
        }
        arr[index] = e;
    }
}

int main()
{
	int arr[100];
    int n, e;
    printf("Enter the size of the array\n");
    scanf("%d", &n);

    printf("Enter the sorted array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be inserted in the array\n");
    scanf("%d", &e);

    insertEle(e, arr, n);

	printf("array after inserting the element\n");

    printArray(arr, n+1);
	return 0;
}