#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include "Twin.h"  // Archivo de cabecera personalizado

int main() {
    // Llama a la función que genera las parejas de primos gemelos
    int resultado = parejas();
    
    // Verifica el resultado de la operación
    if (resultado == 0) {
        std::cout << "Se generaron 100 parejas de primos gemelos en PAREJAS.txt\n";
    } else {
        std::cerr << "Error al generar el archivo\n";
    }
    
    return resultado;  // Retorna el código de estado
}

// Implementación de la función que genera 100 pares de primos gemelos
int parejas() {
    // Crea/Abre el archivo para escribir los resultados
    std::ofstream file("PAREJAS.txt");
    
    int contador = 0;  // Contador de parejas encontradas

    // Bucle desde 3 (primer primo gemelo conocido) hasta encontrar 100 parejas
    // Avanza de 2 en 2 (solo números impares)
    for (long candidato = 3; contador < 100; candidato += 2) {
        // Verifica si tanto 'candidato' como 'candidato+2' son primos
        if (isprime(candidato) && isprime(candidato + 2)) {
            contador++;  // Incrementa el contador de parejas
            
            // Calcula la norma euclidiana del par (candidato, candidato+2)
            double norma = std::sqrt(candidato*candidato + (candidato+2)*(candidato+2));
            
            // Escribe en el archivo: número de pareja y norma calculada
            file << contador << " " << norma << "\n";
        }
    }
    
    file.close();  // Cierra el archivo
    return 0;  // Retorna 0 indicando éxito
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
            flag = false;    // No es primo
            break;           // Terminamos el bucle
        }
    }

    return flag;  // Devolvemos el resultado
}