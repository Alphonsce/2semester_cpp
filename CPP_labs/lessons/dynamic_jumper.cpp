#include <iostream>

// Задача прыжков кузнечика +1 и +2 шагами - на каждой клетке свой price - надо найти минимальный price

void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl; 
}

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

int get_minimal_price(int* prices, int n) {
    int* C = new int[n + 1];    // организуем мемоизацию
    C[0] = 0;
    C[1] = prices[1];

    for (int i = 2; i < n + 1; i ++) {
        C[i] = min(C[i - 1], C[i - 2]) + prices[i];     // ясно, что оптмально идти каждый раз на минимальный прайс
    }

    print_array(C, n + 1);

    int price_to_last = C[n];

    delete[] C;
    return price_to_last;
}

int main() {

    int n = 5;
    int* prices = new int[n + 1] {0, 1, 2, 1, 2, 1};
    // мы изначально стоим в клетке с координатой 0 - стоимость попадания в нее тоже 0

    // for (int i = 0; i < n; i++) {
    //     prices[i] = (rand() % 100) + 1;
    // }

    std::cout << get_minimal_price(prices, n) << std::endl;

    delete[] prices;
    return 0;
}