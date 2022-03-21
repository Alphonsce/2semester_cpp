#ifndef DIG_CALCULATION_H
#define DIG_CALCULATION_H

#include <string>
#include <vector>

void dig_leibnitz_pi(long unsigned max_iter, std::string output_path);

void dig_euler_pi(long unsigned max_iter, std::string output_path);

void dig_gauss_legendre_pi(long unsigned iterations, std::string output_path);

void dig_ramanujan_pi(long unsigned iterations, std::string output_path);

void dig_pi_from_arctans(
    std::vector<long double> arctan_arguments,    // аргументы арктенгенсов
    std::vector<long double> arctan_coefs,        // коэффициенты при арктангенсах
    long long unsigned max_iter, std::string output_path);

void dig_viete_pi(long unsigned iterations, std::string output_path);

#endif