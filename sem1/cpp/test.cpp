#include<iostream>
using namespace std;


class Base1{
    int a = 0;
    public:
    void pa(){
        // cout << a;
    }
};

class d:public Base1{

};
// class c:protected Base1{
//     public:
//     void pc(d o){
//         o.pa();
//     }
// };

int main(){
    d o;
    cout << o.a;
    return 0;
}