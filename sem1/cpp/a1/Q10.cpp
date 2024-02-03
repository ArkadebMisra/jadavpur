#include <iostream>
#include <cmath>

class VolumeCalculator {
public:
    
    double calculateVolume(int side) {
        return pow(side, 3);
    }

    double calculateVolume(double length, double width, double height) {
        return length * width * height;
    }

    double calculateVolume(double radius, double height) {
        return (1.0 / 3) * M_PI * pow(radius, 2) * height ;
    }

    double calculateVolume(int radius, double height) {
        return M_PI * pow(radius, 2) * height;
    }

    double calculateVolume(double radius) {
        return (4.0 / 3) * M_PI * pow(radius, 3);
    }
};

int main() {
    VolumeCalculator calculator;

    int choice;
    do {
        // Display menu
        std::cout << "\nVolume Calculator Menu\n";
        std::cout << "1. Cube\n";
        std::cout << "2. Cuboid\n";
        std::cout << "3. Cone\n";
        std::cout << "4. Cylinder\n";
        std::cout << "5. Sphere\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int side;
                std::cout << "Enter the side length of the cube: ";
                std::cin >> side;
                std::cout << "Volume of Cube: " << calculator.calculateVolume(side) << std::endl;
                break;
            }
            case 2: {
                double length, width, height;
                std::cout << "Enter the length, width, and height of the cuboid: ";
                std::cin >> length >> width >> height;
                std::cout << "Volume of Cuboid: " << calculator.calculateVolume(length, width, height) << std::endl;
                break;
            }
            case 3: {
                double radius, height;
                std::cout << "Enter the radius and height of the cone: ";
                std::cin >> radius >> height;
                std::cout << "Volume of Cone: " << calculator.calculateVolume(radius, height) << std::endl;
                break;
            }
            case 4: {
                double height;
                int radius;
                std::cout << "Enter the radius and height of the cylinder: ";
                std::cin >> radius >> height;
                std::cout << "Volume of Cylinder: " << calculator.calculateVolume(radius, height) << std::endl;
                break;
            }
            case 5: {
                double radius;
                std::cout << "Enter the radius of the sphere: ";
                std::cin >> radius;
                std::cout << "Volume of Sphere: " << calculator.calculateVolume(radius) << std::endl;
                break;
            }
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
