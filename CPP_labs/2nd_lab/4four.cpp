#include <iostream>
#include <string>
#include <cstdlib>

const float PI = 3.141592653589793;

short int minus_one_to_n(unsigned n) {
    if (n % 2 == 0)
        return 1;
    return -1;
}

float leibnitz_pi(float precision, unsigned max_iter) {
    // наилучший результат: 3.14159
    float pi_4 = 0;
    int sum_step = 0;
    unsigned delimeter = 1;

    while (std::abs(4 * pi_4 - PI) > precision) {
        pi_4 += minus_one_to_n(sum_step) * (1. / delimeter);
        delimeter += 2;
        sum_step += 1;
        std::cout << pi_4 << std::endl;
        if (sum_step > max_iter) {
            break;
        }
    }  
    return pi_4 * 4;
}

int main() {

    std::cout << leibnitz_pi(0, 500000) << std::endl;
    return 0;
}