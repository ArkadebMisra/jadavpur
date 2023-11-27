#include<stdio.h>


void encode(char str[]){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]>=97 && str[i]<=122){
            str[i] = 97 + (str[i]-97+1)%26;
        }
        else if(str[i]>=65 && str[i]<=90){
            str[i] = 65 + (str[i]-65+1)%26;
        }
        else if(str[i]>=48 && str[i]<=57){
            str[i] = 48 + (str[i]-48+1)%10;
        }
        i++;
    }

}



int main(){
	char str[100];
    printf("Enter a string\n");
    scanf("%[^\n]%*c", str);
    // printf("%s\n",str);
    encode(str);
    printf("Entered string in after encoding:-\n");
    printf("%s\n",str);


	return 0;
}