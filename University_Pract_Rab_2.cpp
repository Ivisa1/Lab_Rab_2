// Начало программы

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
    int min; // минимальное число
    int max; // максимальное число
    char number; // переменная для дальнейшего определения того, что будет выполняться
    int more; // Число, больше которого должно быть в case 
    int less; // Число, меньше которого должно быть в case 

    auto start = steady_clock::now();
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);

    while (true){
        cout << "Введите номер элемента для выполнения: ";
        cin >> number;
        cout << endl;
        switch(number) {
            // ЗАДАНИЕ 1
            case 'a': 
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

                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << result.count() << " nanoseconds" << endl;
                break;
            // ЗАДАНИЕ 3 (максимальный и минимальный элементы массива)
            case '6':
                min = 0;
                max = 0;
                for(int i = 0; i <= count-1; i++){
                    if(array[i] < min){
                        min = array[i];
                        continue;
                    }
                    if(array[i] > max){
                        max = array[i];
                        continue;
                    }
                }
                cout << "Минимальный элемент: " 
                << min << ", максимальный элемент: " << max << endl;
            default:
                break;
        }

        if(number == '0')
            break;
    }
}
