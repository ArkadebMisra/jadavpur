#include <iostream>
using namespace std;
// Inline function to calculate the square of a number
inline int square(int num) { return num * num; }

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    int squareResult = square(number);

    cout << "Square of " << number << " is: " << squareResult << endl;

    return 0;
}
