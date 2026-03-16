#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    cout << "\033[31mMathematics\033[0m" << endl;
    cout << "\033[32mEnglish\033[0m" << endl;
    cout << "\033[34mProgramming\033[0m" << endl;
    cout << "\033[35mHistory\033[0m" << endl;

    cout << endl;

    float pair1 = 9.30;
    float pair2 = 11.10;
    float pair3 = 12.50;

    cout << fixed << setprecision(2);

    cout << setw(10) << pair1 << endl;
    cout << setw(10) << pair2 << endl;
    cout << setw(10) << pair3 << endl;

    return 0;
}