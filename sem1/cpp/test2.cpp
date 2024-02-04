#include<iostream>

using namespace std;

int m(int arr[], int l, int h){
    if(l==h){
        return arr[l];
    }
    else{
        int mid = (l+h)/2;
        // cout << l << " " <<mid <<" " << h<<endl; 
        return max(m(arr, l, mid), m(arr, mid+1, h));
    }
}
int main(){
    int len = 7;

    int arr[7] = {20,4,6,5,10,0,17};
    int ans = m(arr,0,6);

    cout << ans;

    return 0;
}