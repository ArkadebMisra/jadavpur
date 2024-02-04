
#include<stdio.h>
#include <stdlib.h>  

void matmul(double[][100], double[][100]);
void powerMat(double[][100], double[][100],int);
void genR(double[][100]);
void genMat(double[][100]);
void mPr(double[][100], double[][100]);
void display(double[][100], int, int);
int r1, r2, c1, c2;


int main(){
	
	double a[100][100];
	double pow[100][100];
	double r[100][100];
	int p;
	
	printf("Enter one dimention ofthe square matrix\n");
	scanf("%d", &r1);
	printf("Enter value of P\n");
	scanf("%d", &p);
	
	r2 = c1 = c2 = r1;
	
	genMat(a);
	
	powerMat(a, pow, p);
	display(pow, r1, r1);
	
	genR(r);
	
	mPr(pow, r);
	
	
	
	return 0;
}

void genR(double r[][100]){
	for(int i=0;i<r1;i++){
		for(int j=0;j<1;j++){
			r[i][j] = 1.0/r1;
			
		}
		
	}
	printf("Printing generated matrix R\n");
	display(r, r1, 1);	
}

void display(double m[][100], int r, int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%lf ",m[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
void powerMat(double a[][100],double pow[][100], int p){
	for(int i=0;i<r1;i++){
		for(int j=0;j<r1;j++){
			pow[i][j] = a[i][j];
		}
	}
	
	p = p-1;
	while(p--){
		matmul(pow, a);	
	}
}

void genMat(double a[][100]){
	for(int i=0;i<r1;i++){
		double s = 0;
		for(int j=0;j<r1;j++){
			if(j==r1-1){
				a[i][j] = 1-s;
			}
			else{
				double r = (double)(rand()% 100 + 1);
				s+= r;
				a[i][j] = r;
			}
			
		}
		
	}
	printf("Printing generated matrix M\n");
	display(a, r1, r1);
	
};
void matmul(double a[][100], double b[][100]){

	double ans[100][100];
	
	for(int i=0;i<r1;i++){
		
		for(int j=0;j<c2;j++){
			double s = 0;
			for(int k=0;k<c1;k++){
			
				s += a[i][k]*b[k][j];
			}
			ans[i][j] = s;
		}
	}
	
	
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			b[i][j] = ans[i][j];
		}
	}
	

}


void mPr(double a[][100], double b[][100]){
	r2 = r1;
	c2 = 1;

	double ans[100][100];
	
	for(int i=0;i<r1;i++){
		
		for(int j=0;j<c2;j++){
			double s = 0;
			for(int k=0;k<c1;k++){
			
				s += a[i][k]*b[k][j];
			}
			ans[i][j] = s;
		}
	}
	
	
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			printf("%lf ",ans[i][j]);
		}
		printf("\n");
	}
	

}
