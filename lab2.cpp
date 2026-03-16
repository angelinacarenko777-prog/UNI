#include <iostream>
#include <string>

class Student {
private:
    std::string name, surname;
    int age;

public:
    Student(std::string n, std::string s, int a) : name(n), surname(s), age(a) {}

    // getters
    std::string getName() { return name; }
    std::string getSurname() { return surname; }
    int getAge() { return age; }

    // setters
    void setName(std::string n) { name = n; }
    void setSurname(std::string s) { surname = s; }
    void setAge(int a) { age = a; }

    void printInfo() {
        std::cout << "Ім'я: " << name
                  << ", Прізвище: " << surname
                  << ", Вік: " << age << std::endl;
    }

    ~Student() {
        std::cout << "Об'єкт знищено\n";
    }
};

int main() {
    Student st("Ангеліна", "Царенко", 18);
    st.printInfo();

    st.setAge(19);
    std::cout << "Новий вік: " << st.getAge() << std::endl;

    return 0;
}