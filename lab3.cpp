#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {
        std::cout << "Конструктор Person\n";
    }

    virtual void showInfo() const {
        std::cout << "Ім'я: " << name << std::endl;
        std::cout << "Вік: " << age << std::endl;
    }

    virtual ~Person() {
        std::cout << "Деструктор Person\n";
    }
};

class Student : public Person {
private:
    std::string specialty;

public:
    Student(std::string n, int a, std::string s)
        : Person(n, a), specialty(s) {
        std::cout << "Конструктор Student\n";
    }

    void showInfo() const override {
        Person::showInfo();
        std::cout << "Спеціальність: " << specialty << std::endl;
    }

    ~Student() {
        std::cout << "Деструктор Student\n";
    }
};

int main() {
    Person* p = new Student(
        "Ангеліна",
        18,
        "Інженерія програмного забезпечення"
    );

    std::cout << "\nПовна інформація:\n";
    p->showInfo();

    delete p;
    return 0;
}