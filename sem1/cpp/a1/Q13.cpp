#include <iostream>

class Time {
private:
    int hours, minutes, seconds;

public:
    // Overloading '>>' operator to accept time from user
    friend std::istream& operator>>(std::istream& in, Time& t) {
        std::cout << "Enter time (hours:minutes:seconds): ";
        in >> t.hours >> t.minutes >> t.seconds;
        return in;
    }

    // Overloading '+' operator to add two different times
    Time operator+(const Time& other) const {
        Time result;
        int totalSeconds = seconds + other.seconds + 60 * (minutes + other.minutes) + 3600 * (hours + other.hours);
        result.hours = totalSeconds / 3600;
        result.minutes = (totalSeconds % 3600) / 60;
        result.seconds = totalSeconds % 60;
        return result;
    }

    // Overloading '<<' operator to display the time
    friend std::ostream& operator<<(std::ostream& out, const Time& t) {
        out << t.hours << " hours :" << t.minutes << " minutes :" << t.seconds << " seconds";
        return out;
    }

    // Overloading '==' operator to check whether two times are equal
    bool operator==(const Time& other) const {
        return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
    }
};

int main() {
    Time time1, time2, sum;

    // Input two times from the user
    std::cin >> time1;
    std::cin >> time2;

    // Add two times
    sum = time1 + time2;

    // Display the result
    std::cout << "Time 1: " << time1 << std::endl;
    std::cout << "Time 2: " << time2 << std::endl;
    std::cout << "Sum of Time 1 and Time 2: " << sum << std::endl;

    // Check if two times are equal
    if (time1 == time2) {
        std::cout << "Time 1 is equal to Time 2.\n";
    } else {
        std::cout << "Time 1 is not equal to Time 2.\n";
    }

    return 0;
}
 