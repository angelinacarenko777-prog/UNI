#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <numeric>

class InsufficientDataException : public std::exception {
private:
    std::string message;
public:
    explicit InsufficientDataException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

double divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Критична помилка: Спроба ділення на нуль!");
    }
    return a / b;
}

double calculateAverageFromFile(const std::string& filename, int requiredCount) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        throw std::runtime_error("Помилка: Не вдалося відкрити файл '" + filename + "'");
    }

    std::vector<double> numbers;
    double val;
    
    while (file >> val) {
        numbers.push_back(val);
    }

    if (!file.eof() && file.fail()) {
        throw InsufficientDataException("Помилка: У файлі знайдено некоректні дані (не числа).");
    }

    if (numbers.size() < (size_t)requiredCount) {
        throw InsufficientDataException("Помилка: Недостатньо даних. Знайдено " + 
                                        std::to_string(numbers.size()) + ", потрібно " + 
                                        std::to_string(requiredCount));
    }

    double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
    return sum / numbers.size();
}

int main() {
    std::cout << "--- Тест 1: Ділення ---" << std::endl;
    try {
        std::cout << "10 / 2 = " << divide(10, 2) << std::endl;
        std::cout << "10 / 0 = " << divide(10, 0) << std::endl;
    } 
    catch (const std::runtime_error& e) {
        std::cerr << "Спіймано виняток: " << e.what() << std::endl;
    }

    std::cout << "\n--- Тест 2: Робота з файлом ---" << std::endl;
    std::string testFile = "data.txt";
    
    std::ofstream ofs(testFile);
    ofs << "10.5 20.0 30.5 abc";
    ofs.close();

    try {
        int need = 5;
        double avg = calculateAverageFromFile(testFile, need);
        std::cout << "Середнє значення: " << avg << std::endl;
    }
    catch (const InsufficientDataException& e) {
        std::cerr << "Власний виняток: " << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Стандартний виняток: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Невідома помилка!" << std::endl;
    }

    return 0;
}