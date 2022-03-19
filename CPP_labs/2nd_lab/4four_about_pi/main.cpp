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

    long unsigned iterations = 100;

    std::cout << pi_from_arctans(
        {1.},
        {1.},
        0.,
        iterations, "/home/alphonse/2semester_cpp/CPP_labs/2nd_lab/4four_about_pi/_files/arctan0.csv"
        ) << std::endl;

    std::cout << pi_from_arctans(
        {1. / 2, 1. / 3},
        {1., 1.},
        0.,
        iterations, "/home/alphonse/2semester_cpp/CPP_labs/2nd_lab/4four_about_pi/_files/arctan1.csv"
        ) << std::endl;

    std::cout << pi_from_arctans(
        {1. / 5, 1. / 239},
        {4., -1.},
        0.,
        iterations, "/home/alphonse/2semester_cpp/CPP_labs/2nd_lab/4four_about_pi/_files/arctan2.csv"
        ) << std::endl;
    
    std::cout << pi_from_arctans(
        {1. / 8, 1. / 57, 1. / 239},
        {6., 2., 1.},
        0.,
        iterations, "/home/alphonse/2semester_cpp/CPP_labs/2nd_lab/4four_about_pi/_files/arctan3.csv"
        ) << std::endl;

    std::cout << pi_from_arctans(
        {1. / 57, 1. / 239, 1. / 682, 1. / 12943},
        {44., 7., -12., 24.},
        0.,
        iterations, "/home/alphonse/2semester_cpp/CPP_labs/2nd_lab/4four_about_pi/_files/arctan4.csv"
    ) << std::endl;

    return 0;
}