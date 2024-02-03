#include <iostream>
using namespace std;

class Child {
public:
    ~Child() {
        cout << "Child destroyed" << endl;
    }   
};

class Parent {
private:
    Child* child;
public:
    Parent() {
        child = new Child();
    }

    ~Parent() {
        if(child != NULL) {
            cout << "Error: Child not destroyed yet" << endl; 
        }
        else {
            cout << "Parent destroyed" << endl;
        }
    }

    void freeChild() { 
        delete child;
        child = NULL;
    }
};

int main() {
    Parent *parent = new Parent();
   
    delete parent; // Error
    
    parent->freeChild(); 
    delete parent; // Now works
    
    return 0;
}