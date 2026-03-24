#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Shape {
public:
    virtual void draw() const = 0;
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() const override { cout << "Малюємо коло." << endl; }
    double area() const override { return M_PI * radius * radius; }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    void draw() const override { cout << "Малюємо прямокутник." << endl; }
    double area() const override { return width * height; }
};

class Animal {
public:
    virtual void sound() const = 0;
    virtual ~Animal() {}
};

class Dog : public Animal { public: void sound() const override { cout << "Гав-гав!" << endl; } };
class Cat : public Animal { public: void sound() const override { cout << "Мяу!" << endl; } };

int main() {
    vector<Shape*> shapes;
    int choice;
    int n;

    cout << "Скільки фігур ви хочете створити? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Оберіть фігуру (1 - Коло, 2 - Прямокутник): ";
        cin >> choice;

        if (choice == 1) {
            double r;
            cout << "Введіть радіус: ";
            cin >> r;
            shapes.push_back(new Circle(r));
        } else if (choice == 2) {
            double w, h;
            cout << "Введіть ширину та висоту: ";
            cin >> w >> h;
            shapes.push_back(new Rectangle(w, h));
        }
    }

    cout << "\n--- Результати обробки масиву покажчиків ---" << endl;
    for (const auto& s : shapes) {
        s->draw();
        cout << "Площа: " << s->area() << endl;
        delete s;
    }

    cout << "\n--- Демонстрація Animal ---" << endl;
    Animal* myPet = new Dog();
    myPet->sound();
    delete myPet;

    return 0;
}