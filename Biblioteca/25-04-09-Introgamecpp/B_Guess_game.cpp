/*
Juego de adivinar un número:
1. Genera un número aleatorio dentro de un rango
2. Pide al usuario que adivine el número
3. Proporciona retroalimentación (mayor/menor) hasta que acierte
*/

#include <iostream>      // Para entrada/salida estándar (cin, cout)
#include <random>       // Para generación de números aleatorios

// Declaración de la función play
void play(int min_val, int max_val);

int main() {
    play(1, 100);  // Primera ronda: números entre 1 y 100
    play(2, 22);   // Segunda ronda: números entre 2 y 22
    
    return 0;      // Indica terminación exitosa
}

// Implementación de la función play
void play(int min_val, int max_val) {
    // Configuración del generador de números aleatorios
    std::random_device rd;  // Fuente de aleatoriedad (hardware)
    std::mt19937 gen(rd()); // Motor Mersenne Twister con semilla aleatoria
    std::uniform_int_distribution<int> distro(min_val, max_val); // Distribución uniforme

    const int NUM = distro(gen);  // Número aleatorio a adivinar
    int guessed_number = NUM/2;   // Valor inicial para comenzar las adivinanzas
    
    const int MIN = min_val;      // Límite inferior del rango
    const int MAX = max_val;      // Límite superior del rango

    std::cout << "\nINICIA EL JUEGO\n";  // Mensaje de inicio

    // Bucle principal del juego
    while(guessed_number != NUM) {
        // Solicitar entrada al usuario
        std::cout << "Adivina un numero entre " << MIN << " y " << MAX << ":\n";
        std::cin >> guessed_number;
        std::cout << "Escribiste: " << guessed_number << "\n";

        // Validar que el número esté dentro del rango
        if (guessed_number < MIN || guessed_number > MAX) {
            std::cout << "El numero no esta en el rango.\n";
            continue;  // Saltar al siguiente ciclo del bucle
        }

        // Proporcionar retroalimentación
        if (guessed_number == NUM) {
            std::cout << "GANASTE!!!!\n";
        } else if (guessed_number > NUM) {
            std::cout << "Te pasaste.\n";  // El número es mayor
        } else {
            std::cout << "Te falta.\n";    // El número es menor
        }
    }
}