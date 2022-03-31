#include <iostream>

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void print_2d_array(int** mat, int rows, int columns) {
    for (int i = 0; i < rows; i++)
        print_array(*mat, columns);
}

void delete_2d_array(int** mat, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

int main() {

    int rows = 3, columns = 4;

    int** mat = new int*[rows];  // массив указателей на 0 элементы
    for (int i = 0; i < columns; i ++) {
        mat[i] = new int[columns]{4, 3, 2, 7};
    }

    print_2d_array(mat, rows, columns);

    return 0;
}