#include <iostream>

void expand(int** pt_arr, int old_size, int new_size) {
    int* new_arr = new int[new_size];
    for (int i = 0; i < old_size; i++) {
        new_arr[i] = (*pt_arr)[i];
    }
    delete[] *pt_arr;
    *pt_arr = new_arr;
}


int main() {

    int* arr = new int[100];
    expand(&arr, 100, 10000);
    return 0;
}