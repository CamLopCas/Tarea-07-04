#include "integration.h"

//Implementacion

double trapezoid(double a, double b, int n, fptr f){ // Implementacion de la funcion-meotodo trapezoid

    double delta = (b-a)/n;
    double f_0 = (f(a))/2;
    double f_n = (f(b))/2;
    double S = 0.0;
    for (int k = 1; k <= n-1; k++){
        double xk = a + k*delta;
        S += f(xk);
    } 
    return delta*(f_0+S+f_n);

}

double simpson(double a, double b, int n, fptr f){ // Implementacion de la funcion-emtodo simpson

    if (n % 2 != 0 ){ // verificacion de paridad de n para el metodo simpson
        n += 1;
    }
    double delta = (b-a)/n;
    double f_0 = f(a);
    double f_n = f(b);
    double S1 = 0.0;
    for (int k = 1; k <= n/2; k++){
        double x2k1 = a + ((2*k)-1)*delta;
        S1 += f(x2k1);
    } 
    double S2 = 0.0;
    for (int k = 1; k <= (n/2)-1; k++){
        double x2k = a + (2*k)*delta;
        S2 += f(x2k);
    }

    return (delta/3)*(f_0+(4*S1)+(2*S2)+f_n);

}
double Gauss_2(double a, double b, fptr f){

    double aux1 = (b-a)/2;
    double aux2 = (b+a)/2;

    // Definir coordenadas
    double x0 = -(std::sqrt(3.0/5.0));
    double x1 = 0.0;
    double x2 = (std::sqrt(3.0/5.0));
    
    //Definir los pesos
    double w0 = 5.0/9.0;
    double w1 = 8.0/9.0;
    double w2 = 5.0/9.0;
    double result = (aux1)*(w0*(f((aux1)*x0 + aux2))+ w1*(f((aux1)*x1 + aux2))+ w2*(f((aux1)*x2 + aux2)));
    return result; 

}

