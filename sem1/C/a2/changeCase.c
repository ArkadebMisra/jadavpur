#include<stdio.h>


void changeCase(char str[]){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]>=97 && str[i]<=122){
            str[i] = str[i]-32;
        }
        else if(str[i]>=65 && str[i]<=90){
            str[i] = str[i]+32;
        }
        i++;
    }

}



int main(){
	char str[100];
    printf("Enter a string\n");
    scanf("%[^\n]%*c", str);
    // printf("%s\n",str);
    changeCase(str);
    printf("Entered string in after changing the case of  alphabets:-\n");
    printf("%s\n",str);


	return 0;
}