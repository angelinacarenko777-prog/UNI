#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    Complex operator/(const Complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;

        double r = (real * other.real + imag * other.imag) / denominator;
        double i = (imag * other.real - real * other.imag) / denominator;

        return Complex(r, i);
    }

    bool operator==(const Complex& other) {
        return real == other.real && imag == other.imag;
    }

    void print() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {

    Complex a(3, 2);
    Complex b(1, 4);

    Complex sum = a + b;
    Complex diff = a - b;
    Complex mult = a * b;
    Complex div = a / b;

    cout << "a = ";
    a.print();

    cout << "b = ";
    b.print();

    cout << "a + b = ";
    sum.print();

    cout << "a - b = ";
    diff.print();

    cout << "a * b = ";
    mult.print();

    cout << "a / b = ";
    div.print();

    if (a == b) {
        cout << "a and b are equal" << endl;
    } else {
        cout << "a and b are not equal" << endl;
    }

    return 0;
}