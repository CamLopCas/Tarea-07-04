#include<iostream>   // Para entrada/salida estándar
#include<cmath>      // Para funciones matemáticas (pow, abs)
#include<iomanip>    // Para manipulación de formato de salida (setprecision)

/**
 * Calcula una aproximación de π usando la fórmula BBP modificada
 * para n Número de términos a usar en la serie
 * retorna Aproximación de π con n términos
 */
double pi_aprox(int n) {
    double pi = 0.0;
    for (int k = 0; k <= n; ++k) {
        // Término k-ésimo de la serie BBP
        double ecuacion = 1.0/std::pow(16, k) * (
            4.0/(8*k + 1) - 
            2.0/(8*k + 4) - 
            1.0/(8*k + 5) - 
            1.0/(8*k + 6)
        );
        pi += ecuacion;  // Acumulamos el término al valor de π
    }
    return pi;
}

int main() {
    // Configuración del formato de salida
    std::cout << std::setprecision(16);  // 16 dígitos de precisión
    std::cout << std::scientific;        // Notación científica

    // Encabezado de la tabla
    std::cout << "n\tπ(n)≈\t\t\tError relativo≈\n";
    std::cout << "--------------------------------------------------------------\n";

    // Calculamos y mostramos aproximaciones para n de 1 a 20
    for (int n = 1; n <= 20; ++n) {
        double aprox = pi_aprox(n);
        double relative_error = std::abs(1.0 - (aprox/M_PI));  // Error relativo
        std::cout << n << "\t" << aprox << "\t" << relative_error << "\n";
    }
    
    return 0;
}