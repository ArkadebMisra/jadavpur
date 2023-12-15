#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct account
{
    char accno[30];
    char name[50];
    int balance;
} ACC;
void displayAcc(ACC a[], int n)
{
    int i =0;
    while(i<n)
    {
        
        if(a[i].balance < 1000)
        {
            printf("%s %s %d\n",a[i].accno,a[i].name,a[i].balance);
            
        }
        i++;
    }
}
void depositWithdraw(ACC a[], int n)
{
    char acc[30];
    int amt,c;
    char ch;
    printf("Enter account number, amount, and code (1 for deposit and 0 for withdraw)\n");
    scanf("%[^,], %d, %d",acc,&amt,&c);
    int i =0;
    while(i<n)
    {
        
        if(strcmp(a[i].accno,acc)==0)
        {
            if(c==1)
            {
                a[i].balance += amt;
            }
            else if(c==0)
            {
                if(a[i].balance>amt)
                a[i].balance -= amt;
                else
                printf("The balance is insufficient for the specific withdrawal\n");
            }
            printf("%s %s %d\n",a[i].accno,a[i].name,a[i].balance);
        }
        i++;
    }
}
int main()
{
    ACC a[200];
    FILE *fp;
    fp = fopen("account.txt","r");
    int i=0,flg=0,cv=0,cc=0,cw=0,ca=0;
    
    char c;
    if(!fp)
    printf("Error opening file to read");
    else
    {
        while(!feof(fp))
        {
            fscanf(fp,"%[^,],%[^,],%d\n",a[i].accno,a[i].name,&a[i].balance,&c);
            i++;
        }
        displayAcc(a,i);
        depositWithdraw(a,i);
    }
    fclose(fp);

}