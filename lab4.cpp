#include <iostream>
#include <string>

using namespace std;


class Address {
private:
    string city;
    string street;
    int houseNumber;

public:
    Address(string city, string street, int houseNumber) {
        this->city = city;
        this->street = street;
        this->houseNumber = houseNumber;
    }

    void printAddress() const {
        cout << "Місто: " << city
             << ", Вулиця: " << street
             << ", Будинок: " << houseNumber << endl;
    }
};


class Person {
private:
    string name;
    int age;
    Address address; 

public:
    Person(string name, int age, Address address)
        : address(address) {
        this->name = name;
        this->age = age;
    }

    void printPerson() const {
        cout << "Ім'я: " << name << endl;
        cout << "Вік: " << age << endl;
        address.printAddress(); 
    }
};


int main() {

    Address addr("Івано-Франківськ", "Шевченка", 10);

    Person p("Ангеліна", 18, addr);

    cout << "Інформація про людину:\n";
    p.printPerson();

    return 0;
}
