#include <iostream>
#include <cmath>
#include "prime_utils.h"  // Asumo que contiene la función isprime()

int main(void) {
    // Bucle que recorre desde 300 hasta 396 (400-4)
    for(int ii = 300; ii <= 400-4; ++ii) {
        // Verifica si tanto ii como ii+4 son primos
        if (isprime(ii) && isprime(ii+4)) {
            // Si ambos son primos, imprime el par
            std::cout << "(" << ii << ", " << ii+4 << ") ";
        }
    }
    std::cout << "\n";  // Nueva línea al final
    
    return 0;  // Indica que el programa terminó correctamente
}
