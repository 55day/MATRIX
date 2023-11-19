#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main()
{
	srand(time(0));
	setlocale(0, "");

	int size;
    int min_row = 0;
    int min_col = 0;
    int max_row = 0;
    int max_col = 0;

	cout << "Введите размер матрицы(таблицы): ";
	cin >> size;

    int** matrix = new int*[size];   //Обьявление  двумерного динамического масива.


    for (int i = 0; i < size; i++) {  // Создание двумерного массива и выдел. памяти
        matrix[i] = new int[size];
    }

	for (int i = 0; i < size; i++) {               //Заполнение случайными цифрами и вывод
		for (int j = 0; j < size; j++) {
			matrix[i][j] = 1 + rand() % 10;
			cout << setw(5) << matrix[i][j];
		}
		cout << endl;
	}

    // Поиск минимального и максимального элементов
    int min_element = matrix[0][0];
    int max_element = matrix[0][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] < min_element) {
                min_element = matrix[i][j];
                min_row = i; // кол-во сток
                min_col = j; // кол-во колонок
            }
            if (matrix[i][j] > max_element) {
                max_element = matrix[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    cout << "Индексы минимального элемента: " << min_row << ", " << min_col << endl;
    cout << "Индексы максимального элемента: " << max_row << ", " << max_col << endl;


    for (int i = 0; i < size; i++) {    //Очистка оператив памяти из всех масивов (из каждой ячейки)
        delete[] matrix[i];
    }
    delete[] matrix;
	return 0;
}

