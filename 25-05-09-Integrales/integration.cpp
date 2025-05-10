#include "integration.h"

//Implementacion

double trapezoid(double a, double b, int n, fptr f){

    double delta = (b-a)/n;
    double f_0 = (f(a))/2;
    double f_n = (f(b))/2;
    double S = 0.0;
    for (int k =1; k <= n-1; k++){
        double xk = a + k*delta;
        S += f(xk);
    } 

    return delta*(f_0+S+f_n);

}

double simpson(double a, double b, int n, fptr f){

    if( n % 2 != 0){
        n = n+1;
    }

    double delta = (b-a)/3;
    double f_0 = f(a);
    double f_n = f(b);
    double S1 = 0.0;
    for (int k =1; k<=n/2; k++){
        double x2k1 = a + (2*k-1)*delta;
        S1 += f(x2k1);
    } 
    double S2 = 0.0;
    for (int k =1; k<=n/2-1; k++){
        double x2k = a + (2*k)*delta;
        S1 += f(x2k);
    }

    return delta*(f_0+4*S1+2*S2+f_n);

}