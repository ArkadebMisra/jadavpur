#include<stdio.h>


void merge(int[], int[],int[], int, int);
int main(){
	int a[100];
	int b[100];
	int ans[200];
	
	int l1, l2;
	
	printf("Enter the lenth of the first sorted list\n");
	scanf("%d", &l1);
	
	printf("Enter the first list");
	for(int i=0;i<l1;i++){
		scanf("%d", &a[i]);
	}
	
	printf("Enter the lenth of the second sorted list\n");
	scanf("%d", &l2);
	
	printf("Enter the second list");
	for(int i=0;i<l2;i++){
		scanf("%d", &b[i]);
	}
	
	merge(a, b, ans, l1, l2);
	
	
	printf("the merged sorted list\n");
	for(int i=0;i<l1+l2;i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	
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
