#pragma once
#include <cmath>

using fptr = double(double);

double forward_diff(double x, double h);
double central_diff(double x, double h);