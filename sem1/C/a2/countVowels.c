#include<stdio.h>

void count(char str[], int *v, int *c){
    *v=0;
    *c=0;
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||
        str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||
        str[i]=='O'||str[i]=='U'){
            (*v)++;

        }
        else if(str[i] == ' '){}
        else{
            (*c)++;
        }
        i++;
    }

}


int main(){
	char str[100];
    printf("Enter a string\n");
    scanf("%[^\n]%*c", str);
    int v, c;
    count(str, &v,  &c);
    printf("number of vowels %d\n number of consonants %d\n", v, c);

	return 0;
}