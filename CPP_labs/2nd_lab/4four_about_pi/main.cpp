#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "./includes/utility_foos.hpp"
#include "./includes/constants.hpp"
#include "./includes/pi_calculations.hpp"

int main() {
    std::cout << std::fixed;
    std::cout.precision(25);

    long unsigned iterations = 10000000;
    long double tolerance = 0.1;
// ---------------Arctan methods:------------------
// For digits I plan just manually doing it for each file
    pi_from_arctans(
        {1.},
        {1.},
        tolerance,
        iterations, "/home/alphonse/2semester_cpp/CPP_labs/2nd_lab/4four_about_pi/_files_reach_of_digits/dig_arctan0.csv"
        );

    pi_from_arctans(
        {1. / 2, 1. / 3},
        {1., 1.},
        tolerance,
        iterations, "/home/alphonse/2semester_cpp/CPP_labs/2nd_lab/4four_about_pi/_files/arctan1.csv"
        );

    pi_from_arctans(
        {1. / 5, 1. / 239},
        {4., -1.},
        tolerance,
        iterations, "/home/alphonse/2semester_cpp/CPP_labs/2nd_lab/4four_about_pi/_files/arctan2.csv"
        );
    
    pi_from_arctans(
        {1. / 8, 1. / 57, 1. / 239},
        {6., 2., 1.},
        tolerance,
        iterations, "/home/alphonse/2semester_cpp/CPP_labs/2nd_lab/4four_about_pi/_files/arctan3.csv"
        );

    pi_from_arctans(
        {1. / 57, 1. / 239, 1. / 682, 1. / 12943},
        {44., 7., -12., 24.},
        tolerance,
        iterations, "/home/alphonse/2semester_cpp/CPP_labs/2nd_lab/4four_about_pi/_files/arctan4.csv"
    );

// ------------Other algorithms:-----------------------------

    euler_pi(tolerance, iterations, "/home/alphonse/2semester_cpp/CPP_labs/2nd_lab/4four_about_pi/_files/euler.csv");

    gauss_legendre_pi(tolerance, iterations, "/home/alphonse/2semester_cpp/CPP_labs/2nd_lab/4four_about_pi/_files/gauss.csv");

    ramanujan_pi(tolerance, iterations, "/home/alphonse/2semester_cpp/CPP_labs/2nd_lab/4four_about_pi/_files/ramanujan.csv");

    return 0;
}