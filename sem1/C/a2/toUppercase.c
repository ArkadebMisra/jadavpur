#include<stdio.h>


void toUpper(char str[]){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]>=97 && str[i]<=122){
            str[i] = str[i]-32;
        }
        i++;
    }

}


int main(){
	char str[100];
    printf("Enter a string\n");
    scanf("%[^\n]%*c", str);
    // printf("%s\n",str);
    toUpper(str);
    printf("Entered string in uppercase alphabet:-\n");
    printf("%s\n",str);


	return 0;
}