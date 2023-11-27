#include <stdio.h>
#include<math.h>

double mean(double arr[], int n){
    double s = 0;
    for(int i=0;i<n;i++){
        s += arr[i];
    }
    return s/(double)n;
}

double mode(double arr[], int n){
    double m=arr[0];
    int modeCount=1;
    for(int i=1;i<n;i++){
        int count=1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j])
                count++;
        }
        if(count>modeCount){
            m=arr[i];
            modeCount=count;
        }
    }
    return m;
}

double sd(double arr[], int n){
    double mn = mean(arr, n);
    double term=0;
    for(int i=0;i<n;i++){
        term +=pow(arr[i]- mn, 2);
    }
    term = term/(double)n;
    term= sqrt(term);
    return term;
}


int main()
{
	double arr[100];
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);

    printf("Enter the array elements\n");
    for(int i=0;i<n;i++){
        scanf("%lf", &arr[i]);
    }

	printf("The mean of the array is %lf\n", mean(arr, n));
	printf("The mode of the array is %lf\n", mode(arr, n));
    printf("The standard deviation of the array is %lf\n", sd(arr, n));

	return 0;
}