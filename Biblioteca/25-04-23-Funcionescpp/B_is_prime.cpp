#include <iostream>
#include <cmath>  // Necesario para std::sqrt

// Declaraciones de funciones
bool isprime(long n);  // Verifica si un número es primo
void test(void);       // Función de prueba (no usada en main)

int main(void) {
    int suma = 0;  // Variable para acumular la suma de primos
    
    // Bucle que recorre todos los números de 500 a 1234
    for(int ii = 500; ii <= 1234; ++ii) {
        if (isprime(ii)) {  // Si el número es primo
            suma += ii;      // Lo suma al total
        }
    }
    
    std::cout << suma << "\n";  // Imprime el resultado final
    return 0;
}

// Implementación de la función que verifica si un número es primo
bool isprime(long n) {
    // Casos especiales:
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";
        return false;  // Números <=1 no son primos
    }
    if (n == 2) {
        return true;  // 2 es el único primo par
    }

    // Verificación de divisores:
    bool flag = true;  // Suponemos que es primo inicialmente
    
    // Solo necesitamos verificar divisores hasta la raíz cuadrada de n
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n % ii == 0) {  // Si encontramos un divisor
            flag = false;    // No es primo
            break;           // Termina el bucle
        }
    }
    
    return flag;
}

// Función de prueba (no llamada en main)
void test(void) {
    std::cout << 2 << ": " << isprime(2) << "\n";                // true (primo)
    std::cout << 15 << ": " << isprime(15) << "\n";              // false
    std::cout << 10000000019 << ": " << isprime(10000000019) << "\n";  // Primo grande
    std::cout << 1000000007 << ": " << isprime(1000000007) << "\n";    // Primo grande
}