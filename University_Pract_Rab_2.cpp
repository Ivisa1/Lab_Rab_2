// Начало программы

#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int main() {
    setlocale(0, "");
    int array[100]; // инициализация массива
    char number; // переменная для дальнейшего определения того, что будет выполняться

    while (true){
        cout << "Введите номер элемента для выполнения: ";
        cin >> number;
        cout << endl;
        switch(number) {
            // ЗАДАНИЕ 1
            case '1': 
                // Алгоритм создания массива
                for(int i = 0; i <=99; i++){
                    array[i] = rand() % 199 - 99;
                }
                // Вывод массива в консоль
                for(int i = 0; i <=99; i++){
                    cout << array[i] << " ";
                }
                cout << endl;
                break;
            default:
                break;
            }
        if(number == '0')
            break;
    }
}
