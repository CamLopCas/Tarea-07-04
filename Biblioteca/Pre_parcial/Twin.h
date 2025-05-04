#pragma once  // Directiva para evitar inclusiones múltiples

/**
 * Función principal que procesa argumentos de línea de comandos
 *  argc Número de argumentos
 *  argv Array de argumentos (argv[1] contiene n)
 */
void prime(int argc, char **argv);

/**
 * Encuentra el n-ésimo par de primos gemelos
 * n Número de pares a buscar (n ≥ 1)
 *  El primer primo del n-ésimo par gemelo
 */
long int nth_twin_primes(long n);

/**
 * Verifica si un número es primo
 *  n Número a evaluar
 *  true si n es primo, false en caso contrario
 */
bool isprime(long n);

/**
 * Función adicional para contar parejas de primos gemelos
 *  Número total de parejas encontradas (implementación no visible aquí)
 */
int parejas();