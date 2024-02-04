#include<iostream>
using namespace std;


int main(){
    int len = 7;
    int arr[] = {2,3,0,5,0,7,8};

    int count = 0;
    for(int i=len-1;i>=0;i--){
        if(arr[i]!=0){
            count++;
            arr[len-count] = arr[i];
        }
    }
    for(int i=0;i<len-count;i++){
        arr[i]=0;
    }

    for(int i=0;i<len;i++){
        cout << arr[i]<< " ";
    }
    return 0;
}