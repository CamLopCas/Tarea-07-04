#include <iostream>   // Para entrada/salida estándar
#include "Derivadas.h" // Para las funciones de derivación numérica
#include <cmath>      // Para funciones matemáticas (sin, cos)

// Prototipo de la función (ya está en Derivadas.h)
// double f(double x);

int main(int argc, char **argv) {
    // Configuración de precisión y formato de salida
    std::cout.precision(15);          // Muestra 15 dígitos significativos
    std::cout.setf(std::ios::scientific); // Usa notación científica

    // Punto donde evaluaremos la derivada
    double x = 1.2345;
    // Tamaño del paso para las diferencias finitas
    double h = 1.0e-10;

    // Calculamos las derivadas usando ambos métodos
    double forward_result = forward_diff(x, h);  // Diferencia hacia adelante
    double central_result = central_diff(x, h);  // Diferencia central

    // Mostramos resultados
    std::cout << "Forward Difference: " << forward_result << std::endl;
    std::cout << "Central Difference: " << central_result << std::endl;
    // Valor exacto de la derivada de sin(x²) que es 2xcos(x²)
    std::cout << "Exact Difference  : " << 2*x*std::cos(x*x) << std::endl;

    return 0;  // Fin del programa
}

// Implementación de la función a derivar
double f(double x) {
    return std::sin(x*x);  // f(x) = sin(x²)
    // Su derivada exacta es f'(x) = 2x cos(x²)
}