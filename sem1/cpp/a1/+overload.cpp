#include <iostream>
#include <string>
#include <algorithm>

class ReverseConcatenation {
private:
    std::string str;

public:
    ReverseConcatenation() : str("") {}

    ReverseConcatenation(const std::string& s) : str(s) {}

    // Overloading the + operator for string concatenation and reversal
    ReverseConcatenation operator+(const ReverseConcatenation& other) const {
        ReverseConcatenation result;
        result.str = str + other.str;
        std::reverse(result.str.begin(), result.str.end());
        return result;
    }

    // Display the reversed concatenated string
    void display() const {
        std::cout << "Reversed Concatenated String: " << str << std::endl;
    }
};

int main() {
    // Creating instances of ReverseConcatenation
    ReverseConcatenation str1("Good");
    ReverseConcatenation str2("Morning");

    // Overloaded + operator is used for concatenation and reversal
    ReverseConcatenation result = str1 + str2;

    // Display the result
    result.display();

    return 0;
}
