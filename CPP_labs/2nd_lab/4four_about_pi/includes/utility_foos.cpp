#include <cmath>
#include <math.h>
#include <iostream>
#include <vector>

#include "utility_foos.hpp"

long long unsigned fact(long long unsigned n) {
    long long unsigned fac_n = 1;
    if (n == 0 || n == 1)
        return 1;
    for (long long unsigned i = 1; i <= n; i ++) {
        fac_n *= i;
    }
    return fac_n;
}

short int minus_one_to_n(long long int n) {
    if (n % 2 == 0)
        return 1;
    return -1;
}

long long unsigned power_of_2(long long unsigned pw) {
    long long unsigned result = 1;
    for (long long unsigned i = 0; i < pw; i++) {
        result = result << 1;
    }
    return result;
}

long long unsigned power(long long unsigned n, unsigned p) {
    if (n == 2)
        return power_of_2(p);
    long long unsigned result = 1;
    for (long long unsigned i = 0; i < p; i ++) {
        result *= n;
    }
    return result;
}

// Итеративный метод вычисления арктангенса
long double arctan(long double x, long long unsigned iterations) {
    long double positives = 0;
    long double negatives = 0;
    long double arctan_x = 0;
    long long unsigned number;
    for (long long unsigned k = 1; k <= iterations; k += 1) {
        number = 2  * k - 1;
        if (k % 2 != 0)
            arctan_x += pow(x, number) * (1. / number);
        else
            arctan_x -= pow(x, number) * (1. / number);
    }
    return arctan_x;
}

void print_vector(std::vector<long double> vec) {
    for (int i = 0; i < vec.size(); i ++)
        std::cout << vec[i] << ' ';
    std::cout << std::endl;
}

void print_vector(std::vector<double> vec) {
    for (int i = 0; i < vec.size(); i ++)
        std::cout << vec[i] << ' ';
    std::cout << std::endl;
}

void print_vector(std::vector<float> vec) {
    for (int i = 0; i < vec.size(); i ++)
        std::cout << vec[i] << ' ';
    std::cout << std::endl;
}

void print_vector(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i ++)
        std::cout << vec[i] << ' ';
    std::cout << std::endl;
}