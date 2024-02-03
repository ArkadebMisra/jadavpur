#include<iostream>
#include <limits.h>

using namespace std;


class NumberList{
    int noe;
    int* arr = NULL;

    public:
    NumberList(int n){
        this->noe = n;
        this->arr = new int[n];
        cout << "Enter the elements" << endl;
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
    }

    void sortArr(){
        int i, key, j, n;
        n = noe;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }        
    }

    void display(){
        for(int i=0;i<noe;i++){
            cout << arr[i]<< " ";
        }
    }

    int getMin(){
        int min = INT_MAX;
        for(int i=0;i<noe;i++){
            if(arr[i]< min){
                min = arr[i];
            }
        }
        return min;
    }

    int getMax(){
        int max = INT_MIN;
        for(int i=0;i<noe;i++){
            if(arr[i]> max){
                max = arr[i];
            }
        }
        return max;
    }



};

int main(){
    int n;
    cout << "Enter the length of arry" <<endl;
    cin >> n;
    NumberList nl(n);
    cout << "the list is" << endl;
    nl.display();
    cout << "sorting the list" << endl;
    nl.sortArr();
    cout << "the sorted list" << endl;
    nl.display();
    cout << "the min is " << nl.getMin() << " and the max is " << nl.getMax() << endl;
    return 0;
}
