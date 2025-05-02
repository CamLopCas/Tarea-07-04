#include <string>       // Para std::stoi (conversión de string a int)
#include "prime_utils.h" // Asumo que contiene la función isprime()

int main(int argc, char **argv) {
    // ./programa 300 400 -> argc = 3, argv = ["./programa", "300", "400"]
    
    // Convertimos los argumentos de string a enteros
    int vmin = std::stoi(argv[1]); // Límite inferior del rango
    int vmax = std::stoi(argv[2]); // Límite superior del rango

    // Buscamos pares de primos con diferencia 4
    for(int ii = vmin; ii <= vmax-4; ++ii) {
        // Verificamos si ambos números (ii e ii+4) son primos
        if (isprime(ii) && isprime(ii+4)) {
            // Imprimimos el par encontrado
            std::cout << "(" << ii << ", " << ii+4 << ") ";
        }
    }
    std::cout << "\n"; // Salto de línea final

    return 0; // Indica ejecución exitosa
}
