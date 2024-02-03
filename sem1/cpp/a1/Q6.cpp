#include <iostream>

class LeapYearChecker {
private:
    int year;

public:
    LeapYearChecker(int y) {
        std::cout << "Constructor called for year " << y << ".\n";
        year = y;
        checkLeapYear();
    }

    // Destructor
    ~LeapYearChecker() {
        std::cout << "Destructor called for year " << year << ".\n";
    }

    // Function to check if the year is a leap year
    void checkLeapYear() {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            std::cout << year << " is a leap year.\n";
        } else {
            std::cout << year << " is not a leap year.\n";
        }
    }
};

int main() {
    int inputYear;
    std::cout << "Enter a year: ";
    std::cin >> inputYear;

    LeapYearChecker yearChecker(inputYear);

    return 0;
}
