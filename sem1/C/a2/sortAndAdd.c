#include<stdio.h>
int m, n;

void merge(int[], int[],int[], int, int);

int mapToRow(int i){
	return i%m;
}

int mapToCol(int i){

	return i%n;
}

void insertionSort(int arr[][100], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[mapToRow(i)][mapToCol(i)];
		j = i - 1;

		while (j >= 0 && arr[mapToRow(j)][mapToCol(j)] < key) {
			arr[mapToRow(j+1)][mapToCol(j+1)] = arr[mapToRow(j)][mapToCol(j)];
			j = j - 1;
		}
		arr[mapToRow(j+1)][mapToCol(j+1)] = key;
	}
}

int main(){
	int a[100][100];
	int b[100][100];
	int ans[100][100];
	
	printf("Enter the dimention of the lists\n");
	scanf("%d", &m);

	printf("Enter the dimention of the lists\n");
	scanf("%d", &n);
	
	printf("Enter the first 2d list\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	insertionSort(a, m*n);
	printf("sorted first list\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	
	printf("Enter the second 2d list\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &b[i][j]);
		}
	}

	

	
	insertionSort(b, m*n);

	// printf("sorted second list\n");
	// for(int i=0;i<l2;i++){
	// 	printf("%d ", b[i]);
	// }
	// printf("\n");


	// merge(a, b, ans, l1, l2);
	
	
	// printf("the merged sorted list\n");
	// for(int i=0;i<l1+l2;i++){
	// 	printf("%d ", ans[i]);
	// }
	// printf("\n");
	
}

void merge(int a[], int b[], int ans[],int l1, int l2){
	int l1p=0;
	int l2p=0;
	int i=0;
	while(l1p<l1 && l2p<l2){
		if(a[l1p]<b[l2p]){
			ans[i] = a[l1p];
			l1p++;
			i++;
		}
		else{
			ans[i] = b[l2p];
			l2p++;
			i++;
		}
	}	
	
	while(1){
		if(l1p>=l1){
			break;
		}
		ans[i] = a[l1p];
		i++;
		l1p++;
	}
	
	while(1){
		if(l2p>=l2){
			break;
		}
		ans[i] = b[l2p];
		i++;
		l2p++;
	}
	
}
