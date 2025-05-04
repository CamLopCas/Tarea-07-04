#include <iostream>   // Para entrada/salida estándar
#include <fstream>    // Para manejo de archivos
#include "derivatives.h" // Para las funciones de derivación numérica
#include <cmath>      // Para funciones matemáticas (sin, cos, abs)

// Prototipo de la función a derivar
double f(double x);

int main(int argc, char **argv) {
    // Configuración de precisión y formato de salida
    std::cout.precision(15);           // Muestra 15 dígitos significativos
    std::cout.setf(std::ios::scientific); // Usa notación científica

    double x = 1.2345; // Punto donde evaluaremos la derivada
    double exact_result = 2*x*std::cos(x*x); // Valor exacto de la derivada de sin(x²)

    // Abrimos archivo para guardar resultados
    std::ofstream file("derivatives.txt");
    // Escribimos encabezado (opcional)
    file << "x h forward central error_forward error_central error_forward_richardson error_central_richardson\n";

    // Probamos con diferentes valores de h (desde 1e-20 hasta 1)
    for(double h = 1.0e-20; h <= 1.0; h *= 10.0) {
        // Calculamos derivadas con diferentes métodos
        double forward_result = forward_diff(x, h, f); // Diferencia hacia adelante
        double central_result = central_diff(x, h, f); // Diferencia central
        double richardson_forward_result = richardson(x, h, f, forward_diff, 1); // Richardson con forward
        double richardson_central_result = richardson(x, h, f, central_diff, 2); // Richardson con central

        // Calculamos errores relativos
        double error_forward = std::abs(1.0 - forward_result/exact_result);
        double error_central = std::abs(1.0 - central_result/exact_result);
        double error_forward_r = std::abs(1.0 - richardson_forward_result/exact_result);
        double error_central_r = std::abs(1.0 - richardson_central_result/exact_result);

        // Escribimos resultados en el archivo
        file << x << " " 
             << h << " "
             << forward_result << " "
             << central_result << " "
             << error_forward << " "
             << error_central << " "
             << error_forward_r << " "
             << error_central_r << " "
             << std::endl;
    }
    file.close(); // Cerramos el archivo

    return 0; // Fin del programa
}

// Implementación de la función a derivar
double f(double x) {
    return std::sin(x*x); // f(x) = sin(x²)
    // Su derivada exacta es f'(x) = 2x cos(x²)
}