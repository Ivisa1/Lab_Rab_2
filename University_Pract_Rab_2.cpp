// Ссылка на GitHub - https://github.com/Ivisa1/Lab_Rab_2

// Начало программы

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    setlocale(0, "");

    int count; // Количество элементов массива

    int array[100] = {}; // инициализация массива
    int arrayDop[100] = {}; // дополнительный массив для последующих сортировок
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

        // Выход из программы
        if(number == 0)
            break;

        number -= 1; // для индекса

        switch(instructions[number]) {

            // ЗАДАНИЕ 2.1 (Bubble Sort)
            case 1: {
                // Копирование массива
                for (int i = 0; i < count; i++) {
                    arrayDop[i] = array[i];
                }
                // Сортировка
                start = high_resolution_clock::now(); // работа с промежутком времени

                for (int j = 0; j < count - 1; j++) {
                    for (int i = 0; i < count - 1 - j; i++) {
                        if (arrayDop[i] > arrayDop[i + 1]) {
                            swap(arrayDop[i], arrayDop[i + 1]);
                        }
                    }
                }

                // работа с промежутком времени
                end = high_resolution_clock::now();
                result = duration_cast<nanoseconds>(end - start);

                // Вывод отсортированного массива
                for (int i = 1; i <= count; i++) {
                    cout << arrayDop[i - 1] << " ";
                    if (i % 10 == 0)
                        cout << endl;
                }
                cout << endl;

                cout << "Было затрачено " << result.count() << " наносекунд" << endl; // Вывод времени

                break;
            }

            // ЗАДАНИЕ 2.2 (Shaker Sort)
            case 2: {
                // Копирование массива
                for (int i = 0; i < count; i++) {
                    arrayDop[i] = array[i];
                }

                // Сортировка
                start = high_resolution_clock::now(); // работа с промежутком времени

                for (int j = 0; j < count; j++) {
                    int i;
                    for (i = j; i < count - 1 - j; i++) {
                        if (arrayDop[i] > arrayDop[i + 1]) {
                            swap(arrayDop[i], arrayDop[i + 1]);
                        }
                    }
                    for (i = count - 2 - j; i > j; i--) {
                        if (arrayDop[i] < arrayDop[i - 1]) {
                            swap(arrayDop[i], arrayDop[i - 1]);
                        }
                    }

                }
                // работа с промежутком времени
                end = high_resolution_clock::now();
                result = duration_cast<nanoseconds>(end - start);

                // Вывод отсортированного массива
                for (int i = 1; i <= count; i++) {
                    cout << arrayDop[i - 1] << " ";
                    if (i % 10 == 0)
                        cout << endl;
                }
                cout << endl;
                cout << "Было затрачено " << result.count() << " наносекунд" << endl; // Вывод времени
                break;
            }

            // ЗАДАНИЕ 3 (максимальный и минимальный элементы массива)
            case 6:{
                min = array[0];
                max = array[0];

                start = steady_clock::now(); // работа с промежутком времени

                for (int i = 1; i <= count - 1; i++) {
                    // Нахождение минимального элемента
                    if (array[i] < min) {
                        min = array[i];
                        continue;
                    }
                    // Нахождение максимального элемента
                    if (array[i] > max) {
                        max = array[i];
                        continue;
                    }
                }
                // работа с промежутком времени
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);

                // вывод минимального и максимального элемента
                cout << "Минимальный элемент: " << min << ", максимальный элемент: " << max << endl;

                cout << "Было затрачено " << result.count() << " наносекунд" << endl; // Вывод времени

                break;
            }

            // ЗАДАНИЕ 8 (Изменение расположения элементов по индексам)
            case 8: {
                while (true) {
                    int first, second; // переменные для индексов
                    cout << "Введите индекс первого числа для перемещения: ";
                    cin >> first;
                    cout << "Введите индекс второго числа для перемещения: ";
                    cin >> second;

                    if (first == second)
                        break;

                    start = steady_clock::now();

                    swap(array[first], array[second]); // меняем элементы местами

                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);

                    // вывод массива
                    cout << "Было затрачено " << result.count() << " наносекунд" << endl;
                    for (int i = 1; i <= count; i++) {
                        cout << array[i - 1] << " ";
                        if (i % 10 == 0)
                            cout << endl;
                    }
                    cout << endl;
                    break;
                }
                break;
            }

            // ЗАДАНИЕ 5 (Числа меньше введённого числа)
            case 9:{
                int number; // наше число
                cout << "Введите число, меньше которого должны быть числа в массиве: ";
                cin >> number;
                int mid, left = 0, right = count;
                mid = (left + right) / 2;
                while (left <= right) {
                    mid = (left + right) / 2;
                    if (arrayDop[mid] == number) {
                        break;
                    }
                    if (arrayDop[mid] > number) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                bool k = true;
                while (k) {
                    if (arrayDop[mid] == number) {
                        mid -= 1;
                        continue;
                    }
                    if (arrayDop[mid] > number) {
                        mid -= 1;
                        continue;
                    }
                    if (arrayDop[mid] < number) {
                        break;
                    }
                }
                cout << "Кол-во элементов, которые меньше заданного числа: " << mid + 1 << endl;
                break;
            }

            // ЗАДАНИЕ 6 (Числа больше введённого числа)
            case 10: {
                int number;
                cout << "Введите число, больше которого должны быть числа в массиве: ";
                cin >> number;
                int mid, left = 0, right = count-1;
                mid = (left + right) / 2;
                while (left <= right) {
                    mid = (left + right) / 2;
                    if (arrayDop[mid] == number) {
                        break;
                    }
                    if (arrayDop[mid] > number) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                bool k = true;
                while (k) {
                    if (arrayDop[mid] == number) {
                        mid += 1;
                        continue;
                    }
                    if (arrayDop[mid] > number) {
                        break;
                    }
                    if (arrayDop[mid] < number){
                        mid += 1;
                        continue;
                    }
                }
                cout << "Кол-во элементов, которые больше заданного числа: " << count - mid << endl;
                break;
            }

            // ЗАДАНИЕ 7 (Нахождение числа в отсортированном массиве)
            case 11: {
                int number, k = 0;
                cout << "Введите число, которое хотите найти: ";
                cin >> number;

                // Поиск перебором
                start = steady_clock::now();
                for (int i = 0; i < count; i++) {
                    if (arrayDop[i] == number) {
                        cout << "Ваше число найдено)" << endl;
                        k = 1;
                        break;
                    }
                }
                if (k == 0)
                    cout << "Ваше число не найдено(" << endl;
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "Было затрачено " << result.count() << " наносекунд" << '\n' << endl;

                // Бинарный поиск
                int mid, left = 0, right = count-1;
                mid = (left + right) / 2;
                k = 0;
                start = steady_clock::now();
                while (left <= right) {
                    mid = (left + right) / 2;
                    if (arrayDop[mid] == number) {
                        cout << "Ваше число найдено)" << endl;
                        k = 1;
                        break;
                    }
                    if (arrayDop[mid] > number) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                if (k == 0) {
                    cout << "Ваше число не найдено(" << endl;
                }
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "Было затрачено " << result.count() << " наносекунд" << '\n' << endl;
                break;
            }

            // ЗАДАНИЕ 1 (Создание массива)
            case 12: {
                cout << "Введите количество элементов вашего массива (от 0 до 100): ";
                cin >> count;

                if (count > 100 || count < 1) {
                    cout << "Введено неверное значение" << endl;
                    break;
                }
                // Алгоритм создания массива
                for (int i = 0; i <= count - 1; i++) {
                    array[i] = rand() % 198 - 99;
                }
                // Вывод массива в консоль
                for (int i = 1; i <= count; i++) {
                    cout << array[i - 1] << " ";
                    if (i % 10 == 0)
                        cout << endl;
                }
                cout << endl;
                break;
            }
        }
    }
}