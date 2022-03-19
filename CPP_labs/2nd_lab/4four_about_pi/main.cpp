#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "./includes/utility_foos.hpp"
#include "./includes/constants.hpp"

//-----------Calculation functions below-------------------

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

double gauss_legendre_pi(float tol, long unsigned iterations) {
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

double ramanujan_pi(float tol, long unsigned iterations) {
    double one_over_pi = 0;
    double numerator, delimeter;
    unsigned k = 0;
    do {
        unsigned fac_k = fact(k);
        numerator = fact(4 * k) * (1103 + 26390 * k);
        delimeter = pow(fac_k, 4) * pow(396, 4 * k);
        one_over_pi += numerator / delimeter;
        if (k >= iterations)
            break;
        k ++;
    } while(std::abs(ramanujans_const / one_over_pi - PI) > tol);
    return ramanujans_const / (one_over_pi);
}

long double pi_from_arctans(
    std::vector<long double> arctan_arguments,    // аргументы арктенгенсов
    std::vector<long double> arctan_coefs,        // коэффициенты при арктангенсах
    long double tol, long long unsigned max_iter) {

    long double pi_div4 = 0;
    long long unsigned_iteratons_for_arctans = 10;
    std::vector<long double> arctan_values(arctan_arguments.size(), 0.);

    // checking values for different iterations and looking at tolerance:
    for (unsigned iterations = 2; iterations < max_iter; iterations ++) {
        pi_div4 = 0;
        for (unsigned pos_in_vec = 0; pos_in_vec < arctan_arguments.size(); pos_in_vec ++) {
            arctan_values[pos_in_vec] = arctan(arctan_arguments[pos_in_vec], iterations);
            pi_div4 += arctan_values[pos_in_vec] * arctan_coefs[pos_in_vec];
        }
        if (std::abs(4. * pi_div4 - PI) < tol)
            break;
    }
    print_vector(arctan_values);
    return 4. * pi_div4;
}

int main() {
    std::cout << std::fixed;
    std::cout.precision(25);

    std::cout << pi_from_arctans(
        {1. / 57, 1. / 239, 1. / 682, 1. / 12943},
        {44., 7., -12., 24.},
        0.,
        5000) << std::endl;

    return 0;
}