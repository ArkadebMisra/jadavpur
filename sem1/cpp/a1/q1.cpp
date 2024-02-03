#include <iostream>
using namespace std;

#define PI 3.14

class shape{
    protected:
    double r;
};
class Circle : public shape{
    // double r;
    double area;

    public:
    Circle(double r){
        this->r = r;
        this->area = PI * this->r * this->r;
    }
    
    double getArea(){
        this->area = PI * this->r * this->r;
        return this->area; 
    }

    void setRadius(double r){
        this->r = r;
    }

    double getRadius(){
        return this->r;
    }


};

int main(){
    Circle c(10);
    cout << "the area of circle with radious " << c.getRadius() << " is " << c.getArea() << endl; 


    return 0;
}