#include<iostream>
using namespace std;


class Complex{
    int real;
    int imag;
    
    public:
    Complex(){
        this->real = 0;
        this->imag = 0;
    }
    Complex(int real){
        this->real = real;
        this->imag = 0;
    }
    Complex(int real, int imag){
        this->real = real;
        this->imag = imag;
    }

    //adding to the same object
    void sum(Complex c){
        this->real = this->real + c.real;
        this->imag = this->imag + c.imag;
    }

    //creating a new object containing the sum
    Complex sum2(Complex c){
        Complex newC;
        newC.real = this->real + c.real;
        newC.imag = this->imag + c.imag;
        return newC;
    }

    void show(){
        cout << this->real << " + " << this->imag << "i" << endl; 
    }

};


int main(){
    Complex c1,c4;
    Complex c2(5);
    Complex c3(5, 7);
    c1.show();
    c2.show();
    c3.show();

    c2.sum(c3);
    c2.show();

    c4 = c2.sum2(c3);
    c4.show();

    return 0;
}