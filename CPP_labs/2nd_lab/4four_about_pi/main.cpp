#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "./includes/utility_foos.hpp"
#include "./includes/constants.hpp"
#include "./includes/pi_calculations.hpp"
#include "./includes/dig_calculation.hpp"

void pring_pi_into_files(long double tolerance, long unsigned iterations) {

// ---------------Arctan methods:------------------
// For digits I plan just manually doing it for each file
    pi_from_arctans(
        {1.},
        {1.},
        tolerance,
        iterations, "./_files/arctan0.csv" // "./_files/arctan0.csv"
        );

    pi_from_arctans(
        {1. / 2, 1. / 3},
        {1., 1.},
        tolerance,
        iterations, "./_files/arctan1.csv" 
        );

    pi_from_arctans(
        {1. / 5, 1. / 239},
        {4., -1.},
        tolerance,
        iterations, "./_files/arctan2.csv"
        );
    
    pi_from_arctans(
        {1. / 8, 1. / 57, 1. / 239},
        {6., 2., 1.},
        tolerance,
        iterations, "./_files/arctan3.csv"
        );

    pi_from_arctans(
        {1. / 57, 1. / 239, 1. / 682, 1. / 12943},
        {44., 7., -12., 24.},
        tolerance,
        iterations, "./_files/arctan4.csv"
    );

// ------------Other algorithms:-----------------------------

    euler_pi(tolerance, iterations, "./_files/euler.csv");

    gauss_legendre_pi(tolerance, iterations, "./_files/gauss.csv");

    ramanujan_pi(tolerance, iterations, "./_files/ramanujan.csv");

    leibnitz_pi(tolerance, iterations, "./_files/leibnitz.csv");

    viete_pi(tolerance, iterations, "./_files/viete.csv");
}
//------------------

void print_dig_of_pi_into_files(unsigned iterations) {

// ---------------Arctan methods:------------------
// For digits I plan just manually doing it for each file
    dig_pi_from_arctans(
        {1.},
        {1.},
        iterations, "./_files_reach_of_digits/dig_arctan0.csv"
        );

    dig_pi_from_arctans(
        {1. / 2, 1. / 3},
        {1., 1.},
        iterations, "./_files_reach_of_digits/dig_arctan1.csv" 
        );

    dig_pi_from_arctans(
        {1. / 5, 1. / 239},
        {4., -1.},
        iterations, "./_files_reach_of_digits/dig_arctan2.csv"
        );
    
    dig_pi_from_arctans(
        {1. / 8, 1. / 57, 1. / 239},
        {6., 2., 1.},
        iterations, "./_files_reach_of_digits/dig_arctan3.csv"
        );

    dig_pi_from_arctans(
        {1. / 57, 1. / 239, 1. / 682, 1. / 12943},
        {44., 7., -12., 24.},
        iterations, "./_files_reach_of_digits/dig_arctan4.csv"
    );

// ------------Other algorithms:-----------------------------

    dig_euler_pi(iterations, "./_files_reach_of_digits/dig_euler.csv");

    dig_gauss_legendre_pi(iterations, "./_files_reach_of_digits/dig_gauss.csv");

    dig_ramanujan_pi(iterations, "./_files_reach_of_digits/dig_ramanujan.csv");

    dig_leibnitz_pi(iterations, "./_files_reach_of_digits/dig_leibnitz.csv");

    dig_viete_pi(iterations, "./_files_reach_of_digits/dig_viete.csv");
}

int main() {
    std::cout << std::fixed;
    std::cout.precision(25);

    pring_pi_into_files(-1., 50);
    return 0;
}