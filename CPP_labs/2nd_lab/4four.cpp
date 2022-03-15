#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

const double PI = 3.141592653589793;

const double one_over_sqrt_two = 0.707106781186547524401;
const double ramanujans_const = 0.0002885855652225477091;

// Реализация факториала с хвостовой рекурсией:
unsigned fact(unsigned n) {
    unsigned fac_n = 1;
    if (n == 0 || n == 1)
        return 1;
    for (int i = 1; i <= n; i ++) {
        fac_n *= i;
    }
    return fac_n;
}

unsigned power(unsigned n, unsigned p) {
    unsigned result = 1;
    for (int i = 0; i < p; i ++) {
        result *= n;
    }
    return result;
}

short int minus_one_to_n(long long int n) {
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

float euler_pi(float precision, long unsigned max_iter) {
    // 3.14139|3 - лучшая точность
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

double gauss_legendre(float tol, unsigned iterations) {
    // лучшее значение: 3.14159265358979
    double a_next, b_next, t_next, p_next;
    double a = 1;
    double b = one_over_sqrt_two;
    double t = 0.25;
    unsigned p = 1;
    double pi = 0;
    
    long unsigned i = 0;
    do {
        a_next = 0.5 * (a + b);
        b_next = sqrt(a * b);
        t_next = t - p * (a_next - a) * (a_next - a);
        p = (p << 1);
        pi = (a_next + b_next) * (a_next + b_next) / (4 * t_next);
        if (i >= iterations)
            break;
        a = a_next;
        b = b_next;
        t = t_next;
        i ++;
    } while (std::abs(pi - PI) >  tol);
    return pi;
}

double ramanujan_pi(float tol, unsigned iterations) {
    double one_over_pi = 0;
    double numerator, delimeter;
    unsigned k = 0;
    do {
        unsigned fac_k = fact(k);
        numerator = fact(4 * k) * (1103 + 26390 * k);
        delimeter = power(fac_k, 4) * power(396, 4 * k);
        one_over_pi += numerator / delimeter;
        std::cout << numerator << std::endl; 
        std::cout << delimeter << std::endl;
        std::cout << "--------------------" << std::endl;  
        if (k >= iterations)
            break;
        k ++;
    } while(std::abs(1. / one_over_pi - PI) > tol);
    return 1. / (one_over_pi * ramanujans_const);
}

int main() {
    std::cout << std::fixed;
    std::cout.precision(20);

    // std::cout << gauss_legendre(0, 5) << std::endl;
    std::cout << ramanujan_pi(0, 4) << std::endl; 

    return 0;
}