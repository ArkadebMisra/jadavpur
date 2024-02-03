#include<iostream>
#include<vector>
using namespace std;

int s(vector<int> &v, int n){
    if(n==-1){
        return v[v.size()-1];
    }
    else{
        if(n==v.size()-1){
            return s(v, --n);
        }
        else{
            v[v.size()-1] += v[n];
            return s(v, --n);
        }
    }
}

int main(){
    vector<int> v;

    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(5);
    v.push_back(5);
    v.push_back(7);
    int ans = s(v, v.size()-1);
    cout << ans;

    return 0;
}

