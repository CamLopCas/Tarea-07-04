#include <iostream>
#include <cmath> // Para std::fabs (valor absoluto para floats)



/**
 * Calcula la raíz cuadrada usando el método babilónico
 *  S Número al que se le calculará la raíz
 *  iteraciones Número de repeticiones del algoritmo
 *  Aproximación de la raíz cuadrada de S
 */
double raiz_babilonica(double S, int iteraciones) {
    // Estimación inicial (puede ser S/2.0 o cualquier valor positivo)
    double x = S / 2.0;
    
    // Algoritmo babilónico (se repite 'iteraciones' veces)
    for (int i = 0; i < iteraciones; ++i) {
        x = (x + S / x) / 2.0; // Fórmula de actualización
    }
    
    return x;
}

int main() {
    double numero;
    int iteraciones;
    
    // Entrada de datos
    std::cout << "Ingrese el número para calcular su raíz cuadrada: ";
    std::cin >> numero;
    
    std::cout << "Ingrese el número de iteraciones: ";
    std::cin >> iteraciones;
    
    // Configuración de formato de salida
    std::cout.setf(std::ios::scientific); // Notación científica
    std::cout.precision(15);         // 15 dígitos decimales
    
    // Cálculo y muestra de resultados
    double resultado = raiz_babilonica(numero, iteraciones);
    std::cout << "La raíz cuadrada aproximada es: " << resultado << "\n";
    
    // Comparación con el valor exacto (opcional)
    std::cout << "Valor exacto (sqrt): " << std::sqrt(numero) << "\n";
    
    return 0;
}