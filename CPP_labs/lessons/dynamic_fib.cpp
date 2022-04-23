#include <iostream>

// В жадных алгоритмах мы просто бездумно каждый раз берем локально максимальное/минимальное - локально оптимальное решение для конкретного шага
// В динамическом программировании мы знаем как решать маленькие подзадачи, а потом мы просто повторяем это действие


void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl; 
}

int get_fib(int n) {
    int* F = new int[n + 1];
    F[0] = 0;
    F[1] = 1;

    for (int i = 2; i < n + 1; i ++) {
        F[i] = F[i - 1] + F[i - 2];
    }

    print_array(F, n + 1);

    int fn = F[n];

    delete[] F;
    return fn;
}

int main() {

    int n = 5;

    std::cout << get_fib(n) << std::endl;

    return 0;
}