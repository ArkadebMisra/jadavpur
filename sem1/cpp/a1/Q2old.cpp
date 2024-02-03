#include <iostream>
#include <cmath>

class Triangle {
private:
    float side1, side2, side3;

public:
    // Function to input side lengths from user
    void inputSides() {
        std::cout << "Enter three sides of the triangle: ";
        std::cin >> side1 >> side2 >> side3;
    }

    // Function to calculate the area of the triangle
    float calculateArea() {
        float s = (side1 + side2 + side3) / 2.0; // Calculate semi-perimeter
        return sqrt(s * (s - side1) * (s - side2) * (s - side3)); // Heron's formula for area
    }

    // Function to calculate the perimeter of the triangle
    float calculatePerimeter() {
        return side1 + side2 + side3;
    }

    // Function to print data
    void printData(float area, float perimeter) {
        std::cout << "Area of the triangle: " << area << std::endl;
        std::cout << "Perimeter of the triangle: " << perimeter << std::endl;
    }
};

// Function to take input, calculate area and perimeter
void processTriangle(Triangle &t) {
    t.inputSides();
    float area = t.calculateArea();
    float perimeter = t.calculatePerimeter();
    t.printData(area, perimeter);
}

int main() {
    Triangle triangle;
    processTriangle(triangle); // Process the triangle

    return 0;
}