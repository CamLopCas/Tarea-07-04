#include <iostream>
#include <cmath>  // Para usar std::sqrt

// Declaración de funciones
bool isprime(long n);  // Verifica si un número es primo
void test(void);       // Función de prueba

int main(int argc, char **argv) {
    // Obtiene los límites del rango desde argumentos de línea de comandos
    int vmin = std::stoi(argv[1]);  // Convierte el primer argumento a entero
    int vmax = std::stoi(argv[2]);  // Convierte el segundo argumento a entero

    // Busca pares de primos gemelos en el rango especificado
    for(int ii = vmin; ii <= vmax; ++ii) {
        if (isprime(ii) && isprime(ii+6)) {  // Verifica si ii y ii+6 son primos
            std::cout << "(" << ii << ", " << ii+6 << ")\n";  // Imprime el par
        }
    }
    
    return 0;
}

// Implementación: Verifica si n es primo
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
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {  // Solo verifica hasta √n
        if (n % ii == 0) {  // Si ii divide a n
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