#include <iostream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

// Проверка, что строка содержит только '0' и '1'
bool isBinary(const string& s) {
    for (char c : s) {
        if (c != '0' && c != '1') return false;
    }
    return !s.empty();
}

// Перевод двоичной строки в десятичное число
long long binaryToDecimal(const string& binary) {
    long long result = 0;
    for (char c : binary) {
        result = result * 2 + (c - '0');
    }
    return result;
}

// Перевод десятичного числа в шестнадцатеричную строку
string decimalToHex(long long decimal) {
    if (decimal == 0) return "0";
    const char digits[] = "0123456789ABCDEF";
    string hex = "";
    while (decimal > 0) {
        hex = digits[decimal % 16] + hex;
        decimal /= 16;
    }
    return hex;
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice;
    do {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Перевести двоичное число в шестнадцатеричное\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка буфера

        switch (choice) {
            case 1: {
                string binary;
                cout << "Введите двоичное число: ";
                getline(cin, binary);
                if (!isBinary(binary)) {
                    cout << "Ошибка: введено некорректное двоичное число.\n";
                } else {
                    long long decimal = binaryToDecimal(binary);
                    string hex = decimalToHex(decimal);
                    cout << "Двоичное число " << binary << " соответствует\n";
                    cout << "десятичному: " << decimal << "\n";
                    cout << "шестнадцатеричному: " << hex << "\n";
                }
                break;
            }
            case 0:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
                break;
        }
        if (choice != 0) {
            cout << "Нажмите Enter, чтобы продолжить...";
            cin.get();
        }
    } while (choice != 0);
    return 0;
}