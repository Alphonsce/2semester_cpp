#include <cmath>
#include <math.h>
#include <iostream>

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

long double arctan(long double x, long long unsigned iterations) {
    long double positives = 0;
    long double negatives = 0;
    long double arctan_x;
    for (long long unsigned k = 0; k < iterations; k ++) {
        if (k % 2 != 0)
            positives += pow(x, k) / (2  * k - 1);
        else
            negatives += pow(x, k) / (2  * k - 1);
    }
    return positives - negatives;
}