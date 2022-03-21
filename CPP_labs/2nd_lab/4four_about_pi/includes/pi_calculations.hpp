#ifndef PI_CALCULATIONS_H
#define PI_CALCULATIONS_H

#include <string>
#include <vector>

float leibnitz_pi(float precision, long unsigned max_iter, std::string output_path);

float euler_pi(float precision, long unsigned max_iter, std::string output_path);

double gauss_legendre_pi(float tol, long unsigned iterations, std::string output_path);

double ramanujan_pi(float tol, long unsigned iterations, std::string output_path);

long double pi_from_arctans(
    std::vector<long double> arctan_arguments,    // аргументы арктенгенсов
    std::vector<long double> arctan_coefs,        // коэффициенты при арктангенсах
    long double tol, long long unsigned max_iter, std::string output_path);

double viete_pi(float tol, long unsigned iterations, std::string output_path);

#endif