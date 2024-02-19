#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

// Процедура для проверки столбца на положительность элементов
bool isColumnPositive(double column[MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        if (column[i] <= 0) {
            return false; // Если хотя бы один элемент не положителен, вернуть false
        }
    }
    return true; // Все элементы положительны
}

// Функция для поиска и вывода столбцов с положительными элементами
void findPositiveColumns(double array[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    bool positiveFound = false;

    for (int j = 0; j < cols; ++j) {
        double column[MAX_SIZE];
        for (int i = 0; i < rows; ++i) {
            column[i] = array[i][j];
        }

        if (isColumnPositive(column, rows)) {
            cout << "Столбец " << j + 1 << " содержит только положительные элементы." << endl;
            positiveFound = true;
        }
    }

    if (!positiveFound) {
        cout << "В массиве нет столбцов, содержащих только положительные элементы." << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Введите количество строк (не более " << MAX_SIZE << "): ";
    cin >> rows;
    cout << "Введите количество столбцов (не более " << MAX_SIZE << "): ";
    cin >> cols;

    double array[MAX_SIZE][MAX_SIZE];

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "array[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> array[i][j];
        }
    }

    findPositiveColumns(array, rows, cols);

    return 0;
}
