// Начало программы

#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

int main() {
    setlocale(0, "");
    int array[100]; // инициализация массива
    char number; // переменная для дальнейшего определения того, что будет выполняться
    
    auto start = steady_clock::now();
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);

    while (true){
        cout << "Введите номер элемента для выполнения: ";
        cin >> number;
        cout << endl;
        switch(number) {
            // ЗАДАНИЕ 1
            case '1': 
                start = steady_clock::now();
                // Алгоритм создания массива
                for(int i = 0; i <=99; i++){
                    array[i] = rand() % 199 - 99;
                }
                // Вывод массива в консоль
                for(int i = 0; i <=99; i++){
                    cout << array[i] << " ";
                }
                cout << endl;

                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << result.count() << " nanoseconds" << endl;
                break;
            default:
                break;
        }

        if(number == '0')
            break;
    }
}
