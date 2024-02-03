#include<iostream>
using namespace std;

class MyClass{
    public:
    int i;
    int *j;
    MyClass(int i, int *j){
        this->i = i;
        this->j = j;
    }
};

class MyClassB{
    public:
    int i;
    int *j;
    MyClassB(int i, int *j){
        this->i = i;
        this->j = j;
    }
    MyClassB(const MyClassB &obj){
        this->i = obj.i;
        this->j = new int(*obj.j); 
        
    }
};


int main(){
    int c = 15;
    MyClass a(5, &c);
    MyClass b = a;
    cout << b.i <<" "<< *b.j << endl;
    cout << a.i <<" "<< *a.j << endl;
    *b.j = 10;
    cout << a.i <<" "<< *a.j << endl;
    cout <<"\n\n";
    int d = 20;
    MyClassB f(17, &d);
    MyClassB g = f;    
    cout << f.i <<" "<< *f.j << endl;
    cout << g.i <<" "<< *g.j << endl;
    *f.j = 10;
    cout << g.i <<" "<< *g.j << endl;


    return 0;
}