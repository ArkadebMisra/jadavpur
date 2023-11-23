#include<stdio.h>
void toWords(int[], int, int, int);

int main(){
    int n;
    int len=0;
    // printf("Enter the length of the number\n");
    // scanf("%d", &len);
    printf("Enter the the number\n");
    scanf("%d", &n);
    int arr[500];
    for(int i=0;i<500;i++){
        arr[i] = 0;
    }

    int temp = n;
    int i=1;
    // printf("here");
    while(temp!=0){
        arr[i] = temp%10;
        temp = temp/10;
        // printf("%d ", arr[i]);
        len++;
        i++;
    }
    printf("%d\n", len);

    // for(int i=len;i>0;i--){
    //     printf("%d ", arr[i]);
    // }

    // printf("here");
//1, 10, 100, 1000, 1,000,000 , 1,000,000,000, 1,000,000,000,000
    toWords(arr, len, 1, len);
    printf("\n");
    return 0;
}

void toWords(int n[], int len, int start, int end){
    char *words[] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ",
                    "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", " sixteen ", "seventeen ", "eighteen ",
                    "nineteen ", "tweenteen "};
    char *ty[] = {"ph0", "ph1", "twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety " };

    int arr1[500];
    // printf("%d", len);
    if(len<=3){
        if(n[start+2]!=0){
            printf("%s hundred ", words[n[start+2]]);
        }

        if(n[start+1]!=0 && n[start+1]>1){
            printf("%s %s", ty[n[start+1]], words[n[start+0]]);
        }
        int t = 1;
        t = t*n[start+1]*10 + n[start+0];
        // printf("%d", t);
        if(t<=20){
            // int t = 1;
            // t = t*n[2]*10 + n[1];
            printf("%s ", words[t]);
        }
        // printf("\n");
    }

    else if(len>3 && len<=6){ //100000 999999
        // int i=1;
        // for(int j=4;j<=len;j++){
        //     arr1[i] = n[j];
        //     i++;
        // }
        // printf("%d", i);
        // printf("%d %d %d\n", len-3, 4, len);
        toWords(n,len-3, 4, len); 

        int t=0;
        for(int i=4;i<=len;i++){
            t  = t*10+n[i];
        }
        if(t!=0){
            printf("thousand ");
        }

        toWords(n, 3, 1, 3);
    }

    else if(len>6 && len<=9){ // 1 0 0 0 0 0 0 0
        toWords(n,len-6, 7, len);

        int t=0;
        for(int i=7;i<=len;i++){
            t  = t*10+n[i];
        }
        if(t!=0){
            printf("million ");
        }

        toWords(n, 6, 1, 6);        
    }
    
    else if(len>9 && len<=12){
        toWords(n,len-9, 10, len);

        int t=0;
        for(int i=10;i<=len;i++){
            t  = t*10+n[i];
        }
        if(t!=0){
            printf("billion ");
        }

        toWords(n, 9, 1, 9);        
    }

}