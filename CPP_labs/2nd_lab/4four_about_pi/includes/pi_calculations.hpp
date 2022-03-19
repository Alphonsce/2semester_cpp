#ifndef PI_CALCULATIONS_H
#define PI_CALCULATIONS_H

#include <string>
#include <vector>

float leibnitz_pi(float precision, long unsigned max_iter);

float euler_pi(float precision, long unsigned max_iter);

double gauss_legendre_pi(float tol, long unsigned iterations);

double ramanujan_pi(float tol, long unsigned iterations);

long double pi_from_arctans(
    std::vector<long double> arctan_arguments,    // аргументы арктенгенсов
    std::vector<long double> arctan_coefs,        // коэффициенты при арктангенсах
    long double tol, long long unsigned max_iter, std::string output_path);

#endif