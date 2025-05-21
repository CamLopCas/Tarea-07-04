#include <iostream>
#include "integration.h"

double f(double x);

int main(void){
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);


    std::cout << trapezoid(-1.0, 1.0, 10, f) << "\n";
    std::cout << trapezoid(-1.0, 1.0, 1000, f) << "\n";
    std::cout << trapezoid(-1.0, 1.0, 10000000, f) << "\n";
    std::cout << simpson(-1.0, 1.0, 10, f) << "\n";
    std::cout << Gauss_2(-1.0, 1.0, f) << " \n";

    return 0;
}

double f(double x){
    return 7*x*x*x-8*x*x+3*x+3;
}