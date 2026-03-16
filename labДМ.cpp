#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> numbers;
    int n;

    cout << "Вводьте цілі числа, кратні 2 (0 - завершити введення):" << endl;

    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        if (n % 2 == 0) {
            numbers.insert(n);
        } else {
            cout << "Число не кратне 2, спробуйте ще." << endl;
        }
    }

    cout << "Множина введених чисел:" << endl;

    for (int num : numbers) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}