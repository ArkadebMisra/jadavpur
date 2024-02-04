#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 100
void printMatrix(double M[SIZE][SIZE], int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("%.2lf ", M[i][j]);
        }
        printf("\n");
    }
}
void generateMatrix(double M[SIZE][SIZE],double M1[SIZE][SIZE], int n)
{
    for(int i=0; i<n; i++)
    {
        double sum =0;
        for(int j = 0; j<n-1;j++)
        {
            double t = rand() % 100;
            sum+= t;
            M[i][j] = t;
            M1[i][j] = t;
        }
        M[i][n-1] = 1- sum;
        M1[i][n-1] = M[i][n-1];
    }
}
void matrixPow(double M[SIZE][SIZE],double M1[SIZE][SIZE], int n, int p)
{
    double sum =0;
    int tmp[SIZE][SIZE];
    while(p--)
    {
        for ( int i = 0 ; i < n ; i++ )
        {
            for (int j = 0 ; j < n ; j++ )
            {
                for (int k = 0 ; k < n ; k++ )
                {
                    sum += M1[i][k]*M[k][j];
                }
                tmp[i][j] = sum;
                sum = 0;
            }
        }

        for ( int i = 0 ; i < n ; i++ ) 
        {
            for ( int j = 0 ; j < n ; j++ ) 
            {
                M1[i][j] = tmp[i][j];
            }
        }
    }
    

}
int main()
{
    int n,p;
    double M[SIZE][SIZE];
    double M1[SIZE][SIZE];
    printf("Enter size of matrix\n");
    scanf("%d",&n);
    generateMatrix(M,M1,n);
    printf("Generated Matrix:\n");
    printMatrix(M, n, n);
    printf("Enter value of p\n");
    scanf("%d",&p);
    matrixPow(M,M1,n,p);
    printf("Resultant Matrix:\n");
    printMatrix(M1,n,n);
    double f=1/(double)n;
    double R[n][SIZE];
    for(int i=0;i<n;i++)
    {
        R[i][0]=f; 
    }
    printf("The Column Vector is \n");
    printMatrix(R, n, 1);  

    printf("(M^%d)*R is \n",p);
    double ans[SIZE][SIZE];
    for(int i=0;i<n;i++)
    {
        ans[i][0]=0;
        for(int j=0;j<n;j++)
        {
            ans[i][0]+=M1[i][j]*R[j][0];
        }
    }
    printMatrix(ans, n, 1);

    printf("\nSo we can say R==(M^%d)*R \n",p);

}