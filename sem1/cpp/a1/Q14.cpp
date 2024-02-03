#include <iostream>

class NumberSwapper {
private:
    int num1, num2;

public:
    // Constructor to initialize numbers
    NumberSwapper(int a, int b) : num1(a), num2(b) {}

    // Friend function to swap numbers without using a third variable
    friend void swapNumbers(NumberSwapper& obj);

    // Display function to show the numbers
    void display() {
        std::cout << num1 << " " << num2 << std::endl;
    }
};

// Friend function definition to swap numbers without using a third variable
void swapNumbers(NumberSwapper& obj) {
    obj.num1 = obj.num1 + obj.num2;
    obj.num2 = obj.num1 - obj.num2;
    obj.num1 = obj.num1 - obj.num2;
}

int main() {
    // Create an object of NumberSwapper
    NumberSwapper numbers(5, 10);

    // Display original numbers
    //std::cout << "Original numbers: " << numbers.num1 << " " << numbers.num2 << std::endl;
    std::cout << "Numbers before swapping: ";
    numbers.display();
    // Swap numbers using the friend function
    swapNumbers(numbers);

    // Display numbers after swapping
    std::cout << "Numbers after swapping: ";
    numbers.display();

    return 0;
}
