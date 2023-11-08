#include<stdio.h>


int main(){
    int n;
    int len;
    printf("Enter the length of the number\n");
    scanf("%d", &len);
    printf("Enter the the number\n");
    scanf("%d", &n);
    int arr[500];

    int temp = n;
    int i=1;
    // printf("here");
    while(temp!=0){
        arr[i] = temp%10;
        temp = temp/10;
        // printf("%d ", arr[i]);
        i++;
    }

    // printf("here");
//1, 10, 100, 1000, 1,000,000 , 1,000,000,000, 1,000,000,000,000
    toWords(arr, len);
    return 0;
}

void toWords(int n[], int len){
    char *words[] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ",
                    "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", " sixteen ", "seventeen ", "eighteen ",
                    "nineteen ", "tweenteen "};
    char *ty[] = {"ph0", "ph1", "twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety " };

    int arr1[500];
    // printf("%d", len);
    if(len<=3){
        if(n[3]!=0){
            printf("%s hundred ", words[n[3]]);
        }

        if(n[2]!=0 && n[2]>1){
            printf("%s %s", ty[n[2]], words[n[1]]);
        }
        int t = 1;
        t = t*n[2]*10 + n[1];
        // printf("%d", t);
        if(t<=20){
            // int t = 1;
            // t = t*n[2]*10 + n[1];
            printf("%s ", words[t]);
        }
    }

    

    // int i=1;
    // if(len>12){
    //     arr[i];
    //     i++;
    // }

    // toWords(arr, i);
    // int temp;
    // print(" Trillion ");

    // while(temp!=0){
    //     arr[i] = temp%10;
    //     i++;
    //     temp = temp/=10;
    // }


    // while(i>=1){
    //     if(i>=13){
    //         int arr1[100];
    //         int t = 1;
    //         int j=1;
    //         while(i>=13){
    //             t *= arr[i];
    //             arr1[j] = arr[i];
    //             i--;
    //             j++;
    //         }
    //         toWords(arr1);
    //         print(" Trillion")
    //     };
    // }
}