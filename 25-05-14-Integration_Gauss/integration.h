#pragma once
#include <cmath>
#include <functional>

//Declaracion

using fptr = std::function<double(double)>;
double trapezoid(double a, double b, int n, fptr f);
double simpson(double a, double b, int n, fptr f);

double Gauss_2(double a, double b, fptr f); // Declaracion funcion trapezoid