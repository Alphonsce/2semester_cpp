#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "utility_foos.hpp"
#include "constants.hpp"

void dig_leibnitz_pi(long unsigned max_iter, std::string output_path) {
    // наилучший результат: 3.141592
    float pi_4 = 0;
    float pi = 0;
    long unsigned delimeter = 1;
    unsigned digits = 1;        // number of digits after the dot
    long double tol = pow(10., -1. * digits);

    std::ofstream myfile;
    myfile.open(output_path);
    myfile << "iter,digits\n";
    myfile.precision(20);

    for (int i = 0; i < max_iter; i++) {
        pi_4 += minus_one_to_n(i) * (1. / delimeter);
        pi = 4. * pi_4;
        delimeter += 2;
        if (std::abs(pi - PI) < tol) {
            myfile << i + 1 << ',' << digits << std::endl;
            digits += 1;
            tol = pow(10., -1. * digits);
        }
    }
}

void dig_euler_pi(long unsigned max_iter, std::string output_path) {
    float pi_sq_6 = 0.;
    float pi = 0;
    long unsigned unsquared_delimeter = 1;
    unsigned digits = 1;        // number of digits after the dot
    long double tol = pow(10., -1. * digits);

    std::ofstream myfile;
    myfile.open(output_path);
    myfile << "iter,digits\n";
    myfile.precision(20);

    for (int i = 0; i < max_iter; i++) {
        pi_sq_6 += 1. / (unsquared_delimeter * unsquared_delimeter);
        unsquared_delimeter += 1;
        pi = sqrt(6 * pi_sq_6);
        if (std::abs(pi - PI) < tol) {
            myfile << i + 1 << ',' << digits << std::endl;
            digits += 1;
            tol = pow(10., -1. * digits);
        }
    }
}

void dig_gauss_legendre_pi(long unsigned iterations, std::string output_path) {
    // лучшее значение: 3.14159265358979
    double a_next, b_next, t_next, p_next;
    double a = 1;
    double b = one_over_sqrt_two;
    double t = 0.25;
    unsigned p = 1;
    double pi = 0;

    unsigned digits = 1;        // number of digits after the dot
    long double tol = pow(10., -1. * digits);

    std::ofstream myfile;
    myfile.open(output_path);
    myfile << "iter,digits\n";
    myfile.precision(20);

    for (int i = 0; i < iterations; i++) {
        a_next = 0.5 * (a + b);
        b_next = sqrt(a * b);
        t_next = t - p * (a_next - a) * (a_next - a);
        p = (p << 1);
        pi = (a_next + b_next) * (a_next + b_next) / (4 * t_next);

        if (std::abs(pi - PI) < tol) {
            myfile << i + 1 << ',' << digits << std::endl;
            digits += 1;
            tol = pow(10., -1. * digits);
            // std::cout << i << " : " <<  pi - PI << std::endl;
        }
    
        a = a_next;
        b = b_next;
        t = t_next;
    }
}

void dig_ramanujan_pi(long unsigned iterations, std::string output_path) {
    long double one_over_pi = 0;
    long double pi;
    double numerator, delimeter;
    unsigned k = 0;
    unsigned digits = 1;        // number of digits after the dot
    long double tol = pow(10., -1. * digits);

    std::ofstream myfile;
    myfile.open(output_path);
    myfile << "iter,digits\n";
    myfile.precision(20);

    for (int k = 0; k < iterations; k++) {
        unsigned fac_k = fact(k);
        if (k <= 30) {
            numerator = fact(4 * k) * (1103 + 26390 * k);
            delimeter = pow(fac_k, 4) * pow(396, 4 * k);
        }
        one_over_pi += numerator / delimeter;
        pi = ramanujans_const / (one_over_pi);

        if (std::abs(pi - PI) < tol) {
            myfile << k + 1 << ',' << digits << std::endl;
            digits += 1;
            tol = pow(10., -1. * digits);
            // std::cout << std::abs(pi - PI) << std::endl;
        }
    }
}

void dig_pi_from_arctans(
    std::vector<long double> arctan_arguments,    // аргументы арктенгенсов
    std::vector<long double> arctan_coefs,        // коэффициенты при арктангенсах
    long long unsigned max_iter, std::string output_path) {

    long double pi_div4 = 0;
    long long unsigned_iteratons_for_arctans = 10;
    std::vector<long double> arctan_values(arctan_arguments.size(), 0.);
    unsigned digits = 1;        // number of digits after the dot
    long double tol = pow(10., -1. * digits);

    std::ofstream myfile;
    myfile.open(output_path);
    myfile << "iter,digits\n";
    myfile.precision(20);


    // checking values for different iterations and looking at tolerance:
    for (unsigned iterations = 1; iterations <= max_iter; iterations ++) {
        pi_div4 = 0;
        for (unsigned pos_in_vec = 0; pos_in_vec < arctan_arguments.size(); pos_in_vec ++) {
            arctan_values[pos_in_vec] = arctan(arctan_arguments[pos_in_vec], iterations);
            pi_div4 += arctan_values[pos_in_vec] * arctan_coefs[pos_in_vec];
        }
        if (std::abs(pi_div4 * 4. - PI) < tol) {
            myfile << iterations << ',' << digits << std::endl;
            digits += 1;
            tol = pow(10., -1. * digits);
            // std::cout << std::abs(pi - PI) << std::endl;
        }
    }
    myfile.close();
}

void dig_viete_pi(long unsigned iterations, std::string output_path) {
    double a_n = sqrt(2);
    double two_over_pi = 1.;
    double pi = 1.;
    unsigned digits = 1;        // number of digits after the dot
    long double tol = pow(10., -1. * digits);

    std::ofstream myfile;
    myfile.open(output_path);
    myfile << "iter,digits\n";
    myfile.precision(20);

    for (int i = 0; i < iterations; i++) {
        two_over_pi *= a_n / 2.;
        a_n = sqrt(2 + a_n);
        pi = 2. / two_over_pi;
        if (std::abs(pi - PI) < tol) {
            myfile << i + 1 << ',' << digits << std::endl;
            digits += 1;
            tol = pow(10., -1. * digits);
            // std::cout << i << " : " <<  pi - PI << std::endl;
        }        
    }
}