#include "prime_utils.h"  // Encabezado que contiene la declaración de isprime
#include <cmath>          // Para std::sqrt (raíz cuadrada)

// Implementación de la función que determina si un número es primo
bool isprime(long n) {
    // Verificación de precondiciones: números menores o iguales a 1
    if (n <= 1) {
        // Mensaje de error estándar para números fuera del rango válido
        std::cerr << "Out of range number: " << n << "\n";
        return false;  // Ningún número ≤1 es considerado primo
    }

    // Inicialmente asumimos que el número es primo
    bool flag = true; 

    // Caso especial: el número 2 (único primo par)
    if (n == 2) {
        return true;  // 2 es primo
    }

    // Búsqueda de divisores desde 2 hasta √n + 1
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n % ii == 0) {  // Si encontramos un divisor exacto
            flag = false;    // Marcamos como no primo
            break;           // Terminamos el bucle (no necesitamos más divisores)
        }
    }

    return flag;  // Devolvemos el resultado final
}
