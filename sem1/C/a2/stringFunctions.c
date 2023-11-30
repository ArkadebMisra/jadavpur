#include<stdio.h>
#include<stdlib.h>

int my_strlen(const char *s){
    unsigned int count = 0;
    while(*s!='\0')
    {
        count++;
        s++;
    }
    return count;
}

void my_strcpy(char* destination, const char* source){
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
 
    *destination = '\0';
}

void my_strcat(char* destination, const char* source)
{
    char* ptr = destination + my_strlen(destination);

    while (*source != '\0') {
        *ptr++ = *source++;
    }
 
    *ptr = '\0';
}

int my_strcmp(const char *X, const char *Y){
    while (*X)
    {
        if (*X != *Y) {
            break;
        }
        X++;
        Y++;
    }
 
    return *(const unsigned char*)X - *(const unsigned char*)Y;
}

void my_strrev(char *str){
   char temp;
   int i,length;
   length=my_strlen(str)-1;
   for(i=0;i<my_strlen(str)/2;i++){
      temp=str[i];
      str[i]=str[length];
      str[length--]=temp;
   }
}

int main(){
    int ch;
    char str1[500];
    char str2[500];
    int run=1;
    do{
        printf("\n\n=======================***********=======================\n");
        printf("Choose from these operations to perform it on strings\n");
        printf("1. find length of a string\n"
            "2. copy string to another variable\n"
            "3. concatenate two strings\n"
            "4. reverse the string\n"
            "5. compare two strings\n"
            "6. exit the program\n");
        
        scanf("%d%*c", &ch);
        
        switch(ch)
        {
        case 1:
            printf("Enter a string\n");
            scanf("%[^\n]%*c", str1);
            printf("The length of the string is %d     <========\n", my_strlen(str1));
            break;

        case 2:
            printf("Enter a string to store it in variable str1\n");
            scanf("%[^\n]%*c", str1);
            printf("copying the string to variable str2 from str1\n");
            my_strcpy(str2, str1);
            printf("The string stored in str2 is %s     <========\n", str2);
            break;
        case 3:
            printf("Enter two strings to concatenate them(add the second string at the end of the first string.)\n");
            printf("Enter 1st string\n");
            scanf("%[^\n]%*c", str1);

            printf("Enter 2nd string\n");
            scanf("%[^\n]%*c", str2);

            my_strcat(str1, str2);
            printf("The concatenated string is %s     <========\n", str1);
            break;

        case 4:
            printf("Enter a string\n");
            scanf("%[^\n]%*c", str1);
            my_strrev(str1);
            printf("The reversed string is %s     <========\n", str1);
            break;

        case 5:
            printf("Enter two strings to compare them\n");
            printf("Enter 1st string\n");
            scanf("%[^\n]%*c", str1);

            printf("Enter 2nd string\n");
            scanf("%[^\n]%*c", str2);

            if(my_strcmp(str1, str2)==0){
                printf("The strings are equal     <========\n");
            }
            else{
                printf("The strings are not equal     <========\n");
            }
            break;


        case 6:
            run=0;
            break;
        
        default:
            printf("Enter a correct choice\n");
            break;
        }
    }while(run);
    

    return 0;
}