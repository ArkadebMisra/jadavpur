#include<stdio.h>
#include<stdlib.h>
#define RLEN 100


void mul(int a[], int b[],int lena, int lenb,  int res[]){
    for(int i=0; i<RLEN ; i++){
        res[i] = 0;
    }
    int c=0, l;
    int rIndex= RLEN-1;
    int rStart = RLEN+1;
    int j = lenb-1;
    int k=0;
    while(j>=0){
        l = RLEN - 1- k ;
        for(int i=lena-1;i>=0;i--){
            int tempResL =((b[j]*a[i])+c+res[l])%10;
            int tempC = ((b[j]*a[i])+c+res[l])/10;  
            // res[l] = ((b[j]*a[i])+c+res[l])%10;
            // c = ((b[j]*a[i])+c+res[l])/10;
            res[l] = tempResL;
            c = tempC;
            rStart = rStart>l?l:rStart;
            l--;
        }
        if(c>0){
            res[l]=c;
            rStart = rStart>l?l:rStart;
            l--;
        }
        c=0;
        k++;
        j--;

    }

    j=0;
    for(int i=rStart;i<RLEN;i++){
        printf("%d",res[i]);
        res[j] = res[i];
        j++;
    }
    printf("\n");
    for(;j<RLEN;j++){
        res[j] = -1;
    }


}

void printRes(int res[]){
    int i=0;
    while(res[i]!=-1 && i<RLEN){
        printf("%d",res[i]);
        i++;
    }
    printf("\n");
}

int main(){
    int a[4] = {9, 2, 3, 4};
    int b[4] = {1, 2, 7, 4};
    int res[RLEN];
    mul(a, b, 4, 4, res);
    printRes(res);


    return 0;
}