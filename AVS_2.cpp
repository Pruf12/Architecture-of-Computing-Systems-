 #include <iostream>  
#include <vector>  
#include <iomanip>  
#include <limits>  

using namespace std;  

int main() {  
    setlocale(LC_ALL, "RU");  
    vector<float> numbers;  
    float num;  
    cout << "Введите числа в формате IEEE 754 (float), завершите ввод 0: ";  
    while (cin >> num && num != 0) {  
        numbers.push_back(num);  
    }  
    if (numbers.empty()) {  
        cout << "Массив пуст." << endl;  
        return 0;  
    }  
    float sum = 0;  
    for (float n : numbers) {  
        sum += n;  
    }  
    float average = sum / numbers.size();  
    cout << "Среднее значение: " << average << endl;  
    return 0;  
}  