// Ссылка на GitHub - https://github.com/Ivisa1/Lab_Rab_2

// Начало программы

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    setlocale(0, "");

    int count; // Количество элементов массива
    cout << "Введите количество элементов вашего массива (от 0 до 100): ";
    cin >> count;

    int array[100]; // инициализация массива
    int arrayDop[100]; // дополнительный массив для последующих сортировок
    int instructions[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // набор инструкций программы
    int min; // минимальное число
    int max; // максимальное число
    int number; // переменная для дальнейшего определения того, что будет выполняться
    int more; // Число, больше которого должно быть в case
    int less; // Число, меньше которого должно быть в case

    // Переменыые для нахождения времени
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);

    // Основа программы
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
                // Алгоритм создания массива
                for(int i = 0; i <=count-1; i++){
                    array[i] = rand() % 198 - 99;
                }
                // Вывод массива в консоль
                for(int i = 0; i <=count-1; i++){
                    cout << array[i] << " ";
                }
                cout << endl;
                break;
            // ЗАДАНИЕ 2.1 (Bubble Sort)
            case 1:
                // Копирование массива
                for(int i = 0; i < count; i++){
                    arrayDop[i] = array[i];
                }

                // Сортировка
                start = high_resolution_clock::now(); // работа с промежутком времени

                for(int j = 0; j < count-1; j++){
                    for(int i = 0; i < count-1-j; i++){
                        if(arrayDop[i] > arrayDop[i+1]){
                            swap(arrayDop[i], arrayDop[i+1]);
                        }
                    }
                }

                // работа с промежутком времени
                end = high_resolution_clock::now();
                result = duration_cast<nanoseconds>(end - start);

                // Вывод отсортированного массива
                for(int i = 0; i < count; i++){
                    cout << arrayDop[i] << " ";
                }
                cout << endl;

                cout << result.count() << " nanoseconds" << endl; // Вывод времени

                break;
                // ЗАДАНИЕ 3 (максимальный и минимальный элементы массива)
            case 6:
                min = array[0];
                max = array[0];

                start = steady_clock::now(); // работа с промежутком времени

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
                // работа с промежутком времени
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);

                // вывод минимального и максимального элемента
                cout << "Минимальный элемент: " << min << ", максимальный элемент: " << max << endl;

                cout << result.count() << " nanoseconds" << endl; // Вывод времени

                break;
        }
    }
}
// тест 2
