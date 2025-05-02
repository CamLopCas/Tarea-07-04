#include <iostream>      // Para entrada/salida estándar (std::cout)
#include <cmath>         // Para funciones matemáticas (aunque no se usa directamente aquí)
#include "prime_utils.h" // Para la función isprime()

int main(void) {
    long suma = 0; // Variable para acumular la suma (usamos long para evitar desbordamiento)
    
    // Bucle que recorre todos los números desde 500 hasta 1234
    for(int ii = 500; ii <= 1234; ++ii) {
        // Verificamos si el número actual (ii) es primo
        if (isprime(ii)) {  // Equivalente a isprime(ii) == true
            suma += ii;     // Si es primo, lo sumamos al total acumulado
        }
    }
    
    // Imprimimos el resultado final
    std::cout << suma << "\n";
    
    return 0; // Indica que el programa terminó exitosamente
}