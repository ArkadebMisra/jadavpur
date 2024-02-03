#include <iostream>
using namespace std;



class Aclass{
    int avar;
    public:
    Aclass(){
        this->avar = 0;
    }
    Aclass(int a){
        this->avar = a;
        
    }
    Aclass(const Aclass &o){
        this->avar = o.avar+5;
    }

    // ~Aclass(){
    //     cout << "running costom destructor" << endl;
    // }
    virtual ~Aclass(){
        cout << "destruction of base class -Aclass"<<endl;
    }
    void show(){
        cout << "avar - " << this->avar << endl;
    }


};
class Bclass: public Aclass{
    public:
    Bclass(){
        cout << "constructing derived class"<<endl;
    }
    ~Bclass(){
        cout << "destructing derived" << endl;
    }
};

int main(){
    cout << "creating object with parameterized constructor" << endl;
    Aclass c1(5);
    c1.show();

    cout << "using copy constructor" << endl;
    Aclass c2 = c1;
    c2.show();

    Bclass *d = new Bclass();  
    Aclass *b = d;
    delete b;

    cout << "now destructor" << endl;



    return 0;
}