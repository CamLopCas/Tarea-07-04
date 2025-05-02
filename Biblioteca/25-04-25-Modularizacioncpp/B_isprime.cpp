#include <iostream>   // Para entrada/salida estándar (cout, cin)
#include <cmath>      // Para funciones matemáticas (como sqrt, aunque no se usa directamente aquí)
#include "prime_utils.h"  // Archivo de cabecera que contiene la función isprime()

// Declaración de función de prueba (no se usa en main)
void test(void);

int main(void) {
    // Bucle que recorre todos los números desde 2 hasta 150
    for(int ii = 2; ii <= 150; ++ii) {
        // Verifica si el número actual (ii) es primo
        if (isprime(ii)) {
            // Si es primo, lo imprime seguido de un salto de línea
            std::cout << ii << "\n";
        }
    }

    return 0;  // Indica que el programa terminó correctamente
}

// Implementación de la función de prueba
void test(void) {
    // Pruebas de ejemplo para la función isprime()
    std::cout << 2 << ": " << isprime(2) << "\n";                // Debería ser true (primo)
    std::cout << 15 << ": " << isprime(15) << "\n";              // Debería ser false
    std::cout << 10000000019 << ": " << isprime(10000000019) << "\n";  // Primo grande
    std::cout << 1000000007 << ": " << isprime(1000000007) << "\n";    // Primo grande
}
