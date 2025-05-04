#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Twin.h"  // Archivo de cabecera personalizado

// Implementación de la función para encontrar el n-ésimo par de primos gemelos
long nth_twin_primes(long n) {
    // Validación de entrada
    if (n <= 0) {
        std::cerr << "El número debe ser mayor o igual que 1.\n";
        return -1;  // Valor de error
    }

    long contador = 0;  // Contador de pares encontrados

    // Bucle infinito que busca primos gemelos
    // Comienza en 3 (primer primo gemelo conocido) y avanza de 2 en 2 (solo impares)
    for (long candidato = 3; ; candidato += 2) {
        // Verifica si tanto 'candidato' como 'candidato+2' son primos
        if (isprime(candidato) && isprime(candidato + 2)) {
            contador++;
            if (contador == n) {  // Si encontramos el n-ésimo par
                std::cout << "(" << candidato << ", " << candidato + 2 << ")";
                return candidato;  // Devuelve el primer primo del par
            }
        }
    }
}

// Función principal que procesa argumentos de línea de comandos
void prime(int argc, char **argv) {
    // Convierte el primer argumento a long
    long int n = std::stol(argv[1]);
    // Llama a la función de búsqueda
    nth_twin_primes(n); 
}

// Implementación de la función que verifica si un número es primo
bool isprime(long n) {
    // Casos especiales: números menores o iguales a 1 no son primos
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";
        return false;
    }

    bool flag = true;  // Suponemos que es primo inicialmente

    // El 2 es el único primo par
    if (n == 2) {
        return true;
    }

    // Búsqueda de divisores desde 2 hasta √n + 1
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n % ii == 0) {  // Si encontramos un divisor
            flag = false;   // No es primo
            break;          // Terminamos el bucle
        }
    }

    return flag;  // Devolvemos el resultado
}