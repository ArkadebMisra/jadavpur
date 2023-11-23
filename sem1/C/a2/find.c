#include<stdio.h>


int find(int e, int arr[], int n){
    int index =-1;
    for(int i=0;i<n;i++){
        if(arr[i]==e){
            index = i;
            break;
        }
        return index;
    }

}
int main(){
	int arr[100];
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);

    printf("Enter the array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    int e;
    printf("Enter the element to find\n");
    scanf("%d", &e);
    int ans = find(e, arr, n);

    if(ans ==-1){
        printf("element not found\n");    
    }
    else{
	    printf("The element is found at index %d\n", ans);
    }

	return 0;
}