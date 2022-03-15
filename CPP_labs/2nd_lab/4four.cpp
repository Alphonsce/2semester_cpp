#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

const float PI = 3.141592653589793;

short int minus_one_to_n(unsigned n) {
    if (n % 2 == 0)
        return 1;
    return -1;
}

float leibnitz_pi(float precision, long unsigned max_iter) {
    // наилучший результат: 3.141592
    float pi_4 = 0;
    long unsigned sum_step = 0;
    long unsigned delimeter = 1;

    while (std::abs(4 * pi_4 - PI) > precision) {
        pi_4 += minus_one_to_n(sum_step) * (1. / delimeter);
        delimeter += 2;
        sum_step += 1;
        std::cout << pi_4 << std::endl;
        if (sum_step >= max_iter) {
            break;
        }
    }  
    return pi_4 * 4;
}

float euler_pi(float precision, unsigned max_iter) {
    float pi_sq_6 = 0.;
    long unsigned step = 0;
    long unsigned unsquared_delimeter = 1;
    while (std::abs( sqrt(6 * pi_sq_6) - PI) > precision) {
        pi_sq_6 += 1. / (unsquared_delimeter * unsquared_delimeter);
        unsquared_delimeter += 1;
        step += 1;
        if (step >= max_iter) {
            break;
        }
    }
    float pi = sqrt(6 * pi_sq_6);
    return pi;
}

int main() {
    std::cout << std::fixed;
    std::cout.precision(10);

    std::cout << euler_pi (0, 500) << std::endl;

    return 0;
}