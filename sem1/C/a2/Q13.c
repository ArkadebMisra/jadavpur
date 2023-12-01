#include<stdio.h>
#define SIZE 100
void sortRowWise(int[][SIZE], int, int);

int main(){
	int a[SIZE][SIZE];
	int b[SIZE][SIZE];
	int ans[SIZE][SIZE];
	
	int m1, m2, n1, n2;
	
	printf("Enter the dimension of the first list : ");
	scanf("%d, %d", &m1,&m2);
	
	printf("Enter the first list : \n");
	for(int i=0;i<m1;i++){
        for(int j=0;j<m2;j++){
            scanf("%d", &a[i][j]);
        }
	}
	
	sortRowWise(a, m1, m2);

	printf("Sorted first list : \n");
    for(int i=0;i<m1;i++){
        for(int j=0;j<m2;j++){
		    printf("%d ", a[i][j]);
	    }
	printf("\n");
    }
	

    printf("Enter the dimension of the second list :");
	scanf("%d, %d", &n1,&n2);
	
	printf("Enter the second list : \n");
	for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            scanf("%d", &b[i][j]);
        }
	}
	
	sortRowWise(b, n1, n2);

	printf("Sorted second list : \n");
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
		    printf("%d ", b[i][j]);
	    }
	printf("\n");
    }

    if(m1 == n1 && m2 == n2){
        for(int i=0;i<m1;i++){
            for(int j=0;j<n2;j++){
                ans[i][j] = a[i][j] + b[i][j];
	        }
        }
        sortRowWise(ans, m1, n2);

        printf("Sorted sum of array :\n");
        for(int i=0;i<m1;i++){
            for(int j=0;j<n2;j++){
                printf("%d ", ans[i][j]);
            }
        printf("\n");
        }
    }
    else{
        printf("\nThe given matrices can not be added");
    }
}

void sortRowWise(int m[][SIZE], int r, int c) 
{ 
    int t = 0; 
    
 
    for (int i = 0; i < r; i++) { 
        
       
        for (int j = 0; j < c; j++) { 
            
           
            for (int k = 0; k < c - j - 1; k++) { 
                
                if (m[i][k] > m[i][k + 1]) {  
                    t = m[i][k]; 
                    m[i][k] = m[i][k + 1]; 
                    m[i][k + 1] = t; 
                } 
            } 
        } 
    }
} 