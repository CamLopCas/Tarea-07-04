#include <iostream>
#include <cmath>  // Para usar std::sqrt

// Declaración de funciones
bool isprime(long n);  // Verifica si un número es primo
void test(void);       // Función de prueba (no usada en main)

int main(void) {
    // Busca pares de primos gemelos entre 300 y 444 (450-6)
    for(int ii = 300; ii <= 450-6; ++ii) {
        // Verifica si ii es primo Y si ii+6 también es primo
        if (isprime(ii) && isprime(ii+6)) {  // Optimizado: solo llama a isprime(ii) una vez
            std::cout << "(" << ii << ", " << ii+6 << ")\n";  // Imprime el par
        }
    }
    return 0;
}

// Implementación: Verifica si n es primo
bool isprime(long n) {
    // Casos especiales:
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";  // Mensaje de error
        return false;  // Números <=1 no son primos
    }
    if (n == 2) {
        return true;  // 2 es el único primo par
    }

    // Verificación de divisores:
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {  // Solo verifica hasta √n
        if (n % ii == 0) {  // Si ii divide a n
            return false;    // No es primo (optimizado: sin usar 'flag')
        }
    }
    return true;  // Si no encontró divisores, es primo
}

// Función de prueba (no llamada en main)
void test(void) {
    std::cout << 2 << ": " << isprime(2) << "\n";                // true (primo)
    std::cout << 15 << ": " << isprime(15) << "\n";              // false
    std::cout << 10000000019 << ": " << isprime(10000000019) << "\n";  // Primo grande
    std::cout << 1000000007 << ": " << isprime(1000000007) << "\n";    // Primo grande
}