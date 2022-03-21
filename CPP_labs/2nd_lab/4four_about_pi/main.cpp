#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "./includes/utility_foos.hpp"
#include "./includes/constants.hpp"
#include "./includes/pi_calculations.hpp"

void pring_pi_into_files() {
    std::cout << std::fixed;
    std::cout.precision(25);

    long unsigned iterations = 50;
    long double tolerance = -1.;
    std::vector<std::string> paths = {
        
    };
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

// void print_dig_of_pi_into_files() {
    
// }

int main() {
    std::cout << std::fixed;
    std::cout.precision(25);

    pring_pi_into_files();
    return 0;
}