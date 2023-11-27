#include<stdio.h>
#include<math.h>

int m, n;


double norm(double matrix[][100]){

    double no=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            no += pow(matrix[i][j], 2);
        }
    }
    return sqrt(no);
}
int main(){

    double matrix[100][100];

    printf("Enter the dimention of the matrix m and n\n");
    scanf("%d", &m);
    scanf("%d", &n);

    printf("Enter the matrix\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%lf", &matrix[i][j]);
        }
    }

    double n = norm(matrix);
    printf("The normal of the matrix is %lf\n", n);
    return 0;
}