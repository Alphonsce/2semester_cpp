#include <iostream>

// кузнечик может прыгать либо на написанное в клетке число либо на 1.
// Сколько способов есть дойти до последней клетки

void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl; 
}

int get_ways_numb(int* steps, int n) {

    int* ways = new int[n];    // массив из количества способов попадания
    ways[0] = 0;
    ways[1] = 1;

    for (int i = 2; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if ((j + steps[j] == i) ) { // если мы можем из j позиции попасть в i, то в количество способов еще прибавляем
                std::cout << "j: " << j << " i: " << i << std::endl;
                ways[i] += ways[j];
            }
        }
    }

    std::cout << "----------" << std::endl;
    print_array(ways, n);
    int way_n = *(ways + n - 1);
    delete[] ways;
    return way_n;
}

int main() {

    int n;
    std::cin >> n;

    int* steps = new int[n];
    for (int i = 0; i < n; i ++) {
        std::cin >> *(steps + i);
    }

    std::cout << get_ways_numb(steps, n) << std::endl;

    return 0;
}