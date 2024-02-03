#include <iostream>

class ComplexNumber {
private:
    float real;
    float imag;

public:
    ComplexNumber(float r = 0.0, float i = 0.0) : real(r), imag(i) {}

    void display() const {
        std::cout << "(" << real << " + " << imag << "i)";
    }

    friend ComplexNumber addComplex(const ComplexNumber &c1, const ComplexNumber &c2);
};

ComplexNumber addComplex(const ComplexNumber &c1, const ComplexNumber &c2) {
    ComplexNumber temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

int main() {
    float real1, imag1, real2, imag2;

    std::cout << "Enter real and imaginary parts of first complex number: ";
    std::cin >> real1 >> imag1;

    std::cout << "Enter real and imaginary parts of second complex number: ";
    std::cin >> real2 >> imag2;

    ComplexNumber complex1(real1, imag1);
    ComplexNumber complex2(real2, imag2);

    ComplexNumber result = addComplex(complex1, complex2);

    std::cout << "Sum of ";
    complex1.display();
    std::cout << " and ";
    complex2.display();
    std::cout << " is ";
    result.display();
    std::cout << std::endl;

    return 0;
}
