// 1. displaying the first ten numbers in the Fibonacci series.

// Problem 2 :​

// If  a natural number is a square number, then it has to be​

//       the sum of Successive Odd Numbers starting from 1. ​

// Develop a flowchart to express the logic for displaying the first ten numbers in the series of such square nos.​

// Represent the logic in the form of an algorithm which accepts the count of such numbers as input, and displays  each such square numbers along with its constituents.​

// Finally write the C-code for the problem and execute it.


// Problem 3:​

// If the sum of cubes of each digit of a number is equal to the number itself, then the number is called an Armstrong number. ​

//       For example, 153 = ( 13 ) + ( 53) + ( 33). ​

// Develop a flowchart to express the logic for displaying all such numbers between 1 and 500.​

// Represent the logic in the form of an algorithm which accepts the limit, and displays  each such number.​

// Finally write the C-code for the problem and execute it.


// [ARRAY: Problem 4]     Write a program in C to read n number of values in an array. After that, count a total number of duplicate elements in that array. Then copy the elements except the duplicate elements of that array into another array and display this array in reverse order.​

// ​

// [ARRAY: Problem 5]     Generate all prime numbers below 100. Count them.​

// ​

// [ARRAY: Problem 6]      Display the factors of all composite  numbers below 20 in a tabular form.




#include <stdio.h>
#include<math.h>

int fib();
void armstrong();
void perfectSquare();
void countDuplicates();
void prime();
void composite();

int main(){
    int exit = 1;
    do{
        int choice;
        char trapEnter;
        printf("Enter your choice\n"
                "1. display the first ten numbers in the Fibonacci series.\n"
                "2. display n square numbers\n"
                "3. display all the armstrong number in the range 1 to 500\n"
                "4. count total number of duplicate elements in an array\n"
                "5. generate all prime numbers below 100 and count them\n"
                "6. display factors of all composite numbers below 20 in a tabuler form\n"
                "7. exit\n");
        scanf("%d%c",&choice,&trapEnter);
        switch (choice)
        {
        case 1:
            fib();
            // printf("this feature is being implemented\n\n");
            break;
        
        case 2:
            // printf("this feature is being implemented\n\n");
            perfectSquare();
            break;
       
        case 3:
            // printf("this feature is being implemented\n\n");
            armstrong();
            break;

        case 4:
            // printf("this feature is being implemented\n\n");
            countDuplicates();
            break;

        case 5:
            // printf("this feature is being implemented\n\n");
            prime();
            break;
        
        case 6:
            // printf("this feature is being implemented\n\n");
            composite();
            break;
        
        case 7:
            exit = 0;
            break;
        
        default:
            printf("please Enter valid choice\n\n");
        }
                
    }while(exit);
    return 0;
}

int fib(){
    printf("Printing first 10 fibonacci numbers\n\n");
    int arr[10];
    arr[0] = 0;
    arr[1] = 1;
    for(int i=0;i<10;i++){
        if(i<=1){
            printf("%d ", arr[i]);
        }
        else{
            arr[i] = arr[i-1]+arr[i-2];
            printf("%d ", arr[i]);
        }
    }
    printf("\n\n");
    return 0;
}

 void perfectSquare(){
    int n,i;
    printf("\nEnter the numbers of term : ");
    scanf("%d",&n);
    printf("First %d perfect square expressed as the sum of consecutive odd numbers: \n",n);
    for(i = 2; i <= n+1; i++){
        int num = i;
        int j = 1;
        printf("%d = ",i*i);
        while(num){
            if(num==1)
            printf("%d ",j);
            else
            printf("%d+",j);
            j = j + 2;
            num--;
        }
        printf("\n");
    }
}

void armstrong(){
    int low, high, number, originalNumber, r, count = 0, result = 0;
    printf("Enter two numbers(intervals): ");
    scanf("%d %d", &low, &high);
    printf("Armstrong numbers between %d and %d are: ", low, high);

    if (high < low) {
        high += low;
        low = high - low;
        high -= low;
    }
   
    for (number = low ; number <= high; ++number) {
        originalNumber = number;

    while (originalNumber != 0) {
      originalNumber /= 10;
      ++count;
    }

    originalNumber = number;

    while (originalNumber != 0) {
      r = originalNumber % 10;
      result += pow(r, count);
      originalNumber /= 10;
    }

    if (result == number) {
      printf("%d ", number);
    }
    count = 0;
    result = 0;
  }
}

void countDuplicates()
{
    int n;
    printf("Enter number of values:");
    scanf("%d", &n);
    int arr[1000];
    int unique[1000];
    int i=0, j=0, k=0, d=0;
    printf("Input %d elements in the array :\n",n);
        for(i=0;i<n;i++)
        {
              printf("element - %d : ",i);
              scanf("%d",&arr[i]);
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < i; j++){
                if(arr[i] == arr[j])
                break;
            }
            if(i==j)
            {
                unique[k] = arr[i];
                k++;
            }
        }
        d = n - k;
        printf("No of duplicate element is : %d \n",d);
        for(i=k-1;i>=0;i--)
        {
              printf("%d ",unique[i]);
        }
        printf("\n");
}

void prime()
{
    int prime[100];
    prime[0] = 2;
    int i = 0, j = 0, count = 1, k = 0,fact = 1;
    for(i = 3; i <= 100; i++)
    {
        k = 0;
        for(j = 0; j < count; j++)
        {
           if(i%prime[j] == 0)
           {
               //printf("in 0");
               k++;
               break;
           }
        }
       
        if(k == 0)
        {
            prime[count] = i;
            count++;
        }
        printf("\n");
    }
    printf("Total no of prime numbers: %d\n",count);
     for(i = 0; i < count; i++)
    {
        printf("%d ", prime[i]);
    }
    
}
void composite()
{
    int prime[100];
    prime[0] = 2;
    int i = 0, j = 0, count = 1, k = 0,fact = 1;
    for(i = 3; i <= 20; i++)
    {
        k = 0;
        for(j = 0; j < count; j++)
        {
           if(i%prime[j] == 0)
           {
               //printf("in 0");
               k++;
               printf("\nFactors of %d is: ",i);
               for(fact=1; fact <i; fact++){
                   if(i%fact == 0)
                   printf("%d ",fact);
               }
               break;
           }
        }
       
        if(k == 0)
        {
            prime[count] = i;
            count++;
        }
        
    }
}
