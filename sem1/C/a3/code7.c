#include<stdio.h>
#include<stdlib.h>
#include<string.h>





int main(){
    FILE *fp = fopen("matrix.txt","r");
    int row=0, col=0, temp;
    int matrix[500][500];
    char buff[100];
    int flag=1;
    while(fgets(buff, 100, fp)!=0){
        if(flag){
            col = strlen(buff)-1;
            // printf("%d\n", col);
            for(int i=0;i<col;i++){
                // printf("%d ,%d\n", row, i);
                if(buff[i]=='0')
                    // temp=1;
                    // printf("%d\n", matrix[row][i]);
                    matrix[row][i]=0;
                else
                    // temp=1;
                    matrix[row][i]=1;
            }
            row++;
            flag=0;
        }
        else{
            // matrix = realloc(matrix, (row+1)*col*sizeof(int));
            for(int i=0;i<col;i++){
                if(buff[i]=='0')
                    matrix[row][i]=0;
                else
                    matrix[row][i]=1;
            }
            row++; 
        }
    }
    // printf("%d %d", row, col);
    fclose(fp);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    fp = fopen("matrixres.txt", "w");
    for(int i=0;i<row;i++){
        int sum =0;
        for(int j=0;j<col;j++){
            sum += matrix[i][j];
        }
        fprintf(fp, "%d %d\n", i+1, sum);
    }
    fclose(fp);

    
    return 0;
}