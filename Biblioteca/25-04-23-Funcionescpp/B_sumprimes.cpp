#include <iostream>
#include <cmath>

// Declaración de funciones
bool isprime(long n);  // Verifica si un número es primo
void test(void);       // Función de prueba (no se usa en main)

int main(void) {
    long suma = 0;  // Variable para acumular la suma de primos
    
    // Bucle que recorre desde 500 hasta 1234
    for(int ii = 500; ii <= 1234; ++ii) {
        if (isprime(ii) == true) {  // Si el número es primo
            suma += ii;             // Se suma al total
        }
    }
    std::cout << suma << "\n";  // Imprime el resultado
    return 0;
}

// Implementación de isprime
bool isprime(long n) {
    // Casos especiales:
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";  // Error para n <= 1
        return false;
    }
    if (n == 2) {
        return true;  // 2 es primo
    }

    bool flag = true;  // Supone que es primo inicialmente
    
    // Busca divisores desde 2 hasta sqrt(n)+1
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n % ii == 0) {  // Si encuentra divisor
            flag = false;    // No es primo
            break;           // Termina el bucle
        }
    }
    return flag;  // Retorna el resultado
}

// Función de prueba (no se ejecuta en main)
void test(void) {
    std::cout << 2 << ": " << isprime(2) << "\n";                // true
    std::cout << 15 << ": " << isprime(15) << "\n";              // false
    std::cout << 10000000019 << ": " << isprime(10000000019) << "\n";  // Primo grande
    std::cout << 1000000007 << ": " << isprime(1000000007) << "\n";    // Primo grande
}