#include<iostream>
#include<math.h>
using namespace std;
class Triangle{
    private:
    double side1;
    double side2;
    double side3;

    public:
    void setSides()
    {
        double s1, s2, s3;
        cout<<"Enter sides"<<endl;
        cin >> s1 >> s2 >> s3;
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }
    double calculateArea()
    {
         double s = (side1 + side2 + side3) / 2.0; // Calculate semi-perimeter
        return sqrt(s * (s - side1) * (s - side2) * (s - side3)); ;
    }
    void print();
    double calculatePerimeter();
};
double Triangle:: calculatePerimeter() {
    return side1 + side2 + side3;
}
void Triangle:: print(){

 cout<< "Area:" << this->calculateArea()<< endl;
 cout<< "Area:" << this->calculatePerimeter()<< endl;

}

int main()
{
    Triangle t;
    t.setSides();
    t.calculateArea();
    t.calculatePerimeter();
    t.print();
}