#include <iostream>

int main() {
    long long int n, a = 2, summ = 0;

    std::cin >> n;

    while (a <= n) {
        summ += n / a;
        a *= 2;
    }

    std::cout << summ;

    return 0;
}