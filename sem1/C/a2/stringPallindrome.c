#include<stdio.h>
#include<string.h>

void strRev(char str[], char strRev[]){
    int len = strlen(str);
    int i=len-1;
    int j=0;
    while(i!=-1){
        strRev[j++] = str[i];
        i--;
    }
    strRev[len]='\0';


}


int main(){
    char str[100];
    char revStr[100];
    printf("Enter  string\n");
    scanf("%[^\n]s", str);
    strRev(str, revStr);
    printf("The reversed string is\n");
    printf("%s\n", revStr);
    if(strcmp(str, revStr)==0){
        printf("The string is a pallindrome\n");
    }else{
        printf("The string is not a pallindrome\n"); 
    }

}