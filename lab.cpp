#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point(double xVal = 0, double yVal = 0) {
        x = xVal;
        y = yVal;
    }

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double xVal) { x = xVal; }
    void setY(double yVal) { y = yVal; }

    void print() const {
        cout << "(" << x << ", " << y << ")";
    }
};

class Circle {
private:
    double radius;
    Point center;

public:
    Circle(double r = 1, double x = 0, double y = 0) : center(x,y) {
        radius = r;
    }

    double area() const {
        return M_PI * radius * radius;
    }

    double perimeter() const {
        return 2 * M_PI * radius;
    }

    void print() const {
        cout << "Circle center = ";
        center.print();
        cout << " radius = " << radius << endl;
    }
};

class Rectangle {
private:
    double width;
    double height;
    Point topLeft;

public:
    Rectangle(double w, double h, double x, double y) : topLeft(x,y) {
        width = w;
        height = h;
    }

    double area() const {
        return width * height;
    }

    double perimeter() const {
        return 2 * (width + height);
    }

    void print() const {
        cout << "Rectangle top-left = ";
        topLeft.print();
        cout << " width = " << width << " height = " << height << endl;
    }
};

int main() {

    int a;
    double b;
    string name;

    cout << "Enter integer: ";
    cin >> a;

    cout << "Enter double number: ";
    cin >> b;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Hello " << name << endl;
    cout << "Integer = " << a << endl;
    cout << "Double = " << b << endl;

    Point p1(3,4);
    cout << "Point coordinates: ";
    p1.print();
    cout << endl;

    Circle c1(5,0,0);
    c1.print();
    cout << "Circle area = " << c1.area() << endl;
    cout << "Circle perimeter = " << c1.perimeter() << endl;

    Rectangle r1(4,6,1,1);
    r1.print();
    cout << "Rectangle area = " << r1.area() << endl;
    cout << "Rectangle perimeter = " << r1.perimeter() << endl;

    return 0;
}