#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    FILE *fp;
    fp = fopen("poems.txt","r");
    char wrds[100];
    int i=0,flg=0,cv=0,cc=0,cw=0,ca=0;
    
    char c;
    if(!fp)
    printf("Error opening file to read");
    else
    {
        while(!feof(fp))
        {
            fscanf(fp,"%[^ ] ",wrds,&c);
            int l = strlen(wrds)-1;
            cw++;
            if(strcmp(wrds,"a")==0||strcmp(wrds,"an")==0||strcmp(wrds,"the")==0)
            ca++;
            while(l>=0)
            {
                if(isalpha(wrds[l]))
                if(wrds[l]=='a'||wrds[l]=='e'||wrds[l]=='i'||wrds[l]=='o'||wrds[l]=='u')
                cv++;
                else
                cc++;
                l--;
            }
        }
        printf("vowel: %d\nconsonants: %d\nwords: %d\narticles: %d\n",cv,cc,cw,ca);
    }
}