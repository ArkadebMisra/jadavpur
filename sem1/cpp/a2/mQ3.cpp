#include<iostream>
using namespace std;

class Rectangle{
    int length;
    int breadth;
    public:
    // Rectangle(int length,int breadth){
    //     this->length = length;
    //     this->breadth = breadth;
    // }
    void setLength(int l){
        length = l;
    }
    void setBreadth(int b){
        breadth = b;
    }
    bool operator == (const Rectangle &c){
        if (length == c.length && breadth == c.breadth)
            return true;
        return false;
    }
};


int main(){
    Rectangle R[5];
    for(int i=0;i<5;i++){
        if(i%2==0){
            R[i].setLength(2);
            R[i].setBreadth(4);
        }
        else{
            R[i].setLength(5);
            R[i].setBreadth(7);
        }
    }

    int flag[5] = {0};

    for(int i=0;i<5;i++){
        if(flag[i]==0){
            cout << i <<"th rectangle is equal to rectangles at index ";
            flag[i] = 1;
            for(int j=i+1;j<5;j++){
                if(R[i]==R[j]){
                    flag[j] =1;
                    cout << j << " ";
                }
            }
            cout << endl;
        }
        
    }

    return 0;
}