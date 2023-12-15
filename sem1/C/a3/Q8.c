#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    FILE* fp, *fp1;
    char ch;
 
    // Opening file in reading mode
    fp = fopen("Source.txt", "r");
    fp1 = fopen("Dest.txt","w");
    if(!fp){
        printf("Can not open file");
    }
    else{
        while (!feof(fp)) {
            ch = fgetc(fp);
            ch = toupper(ch);
            fputc(ch, fp1);
        }
        fclose(fp);
        fclose(fp1); 
    }
}
