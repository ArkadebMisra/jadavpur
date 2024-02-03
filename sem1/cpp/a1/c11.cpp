#include<iostream>
#include<cmath>

using namespace std;

class Calculator {
public:
    // Function to reverse the digits of an integer
    void calculate(int m, char ch) {
        if (ch == 'r') {
            int reversedNumber = 0;
            while (m > 0) {
                reversedNumber = reversedNumber * 10 + m % 10;
                m /= 10;
            }
            cout << "Reversed Number: " << reversedNumber << endl;
        }
        else if (ch == 'p') {
            if (isPrime(m)) {
                cout << m << " is a prime number." << endl;
            }
            else {
                cout << m << " is not a prime number." << endl;
            }
        }
        else {
            cout << "Invalid character. Please use 'r' for reverse or 'p' for prime check." << endl;
        }
    }

private:
    // Function to check if a number is prime
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Calculator calculator;

    int num;
    char option;

    cout << "Enter an integer: ";
    cin >> num;

    cout << "Enter 'r' to reverse the digits or 'p' to check for prime: ";
    cin >> option;

    calculator.calculate(num, option);

    return 0;
}
