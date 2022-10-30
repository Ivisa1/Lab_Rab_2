// Начало программы

#include <string>
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

int main() {
    setlocale(0, "");

    int count; // Количество элементов массива
    cout << "Введите количество элементов вашего массива: ";
    cin >> count;

    int array[count]; // инициализация массива
    int instructions[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // набор инструкций программы
    int min; // минимальное число
    int max; // максимальное число
    int number; // переменная для дальнейшего определения того, что будет выполняться
    int more; // Число, больше которого должно быть в case 
    int less; // Число, меньше которого должно быть в case 

    // Переменыые для нахождения времени
    auto start = steady_clock::now();
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);

    while (true){
        cout << "Введите номер элемента для выполнения: ";
        cin >> number;
        cout << endl;

        // Выход из программы
        if(number == 0)
            break;

        number -= 1; // для индекса
        
        switch(instructions[number]){

            // ЗАДАНИЕ 1
            case 12: 
                // работа с промежутком времени
                start = steady_clock::now();

                // Алгоритм создания массива
                for(int i = 0; i <=count-1; i++){
                    array[i] = rand() % 199 - 99;
                }
                // Вывод массива в консоль
                for(int i = 0; i <=count-1; i++){
                    cout << array[i] << " ";
                }
                cout << endl;

                // работа с промежутком времени + вывод времени
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << result.count() << " nanoseconds" << endl;

                break;

            // ЗАДАНИЕ 2.1 (Bubble Sort)
            case 1:
                break;

            // ЗАДАНИЕ 3 (максимальный и минимальный элементы массива)
            case 6:
                min = 0;
                max = 0;

                for(int i = 0; i <= count-1; i++){
                    // Нахождение минимального элемента
                    if(array[i] < min){
                        min = array[i];
                        continue;
                    }
                    // Нахождение максимального элемента
                    if(array[i] > max){
                        max = array[i];
                        continue;
                    }
                }
                // вывод минимального и максимального элемента
                cout << "Минимальный элемент: " 
                << min << ", максимальный элемент: " << max << endl;
            
            default:
                break;
        }
    }
}
