#include<iostream>
using namespace std;

class Singleton{
    int arg;
    static int created;
    static Singleton *obj_pointer;
    Singleton(){
        
    }
    Singleton(const Singleton & o) = delete;
    public:

        static Singleton *create(){
            if(created==1){
               return obj_pointer;
            }
            else{
                created=1;
                // Singleton obj(arg);
                obj_pointer = new Singleton();
                return obj_pointer;
            }
        }
};

int Singleton::created = 0;
Singleton* Singleton::obj_pointer = NULL;

int main(){

    Singleton *b = Singleton::create();
    // cout << b;
    Singleton *c = Singleton::create();
    cout << b <<endl; 
    cout << c << endl;
    return 0;
}