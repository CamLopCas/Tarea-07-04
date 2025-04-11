/*JUego de adivinar un numero
Tener un numero
Preguntar al usuario un numero
Informar si lo adivinio o no
*/

#include <iostream>
#include <random>

// Declaracion
void play( int min_val, int max_val);


int main(void){
    play(1,100);
    play(2,22);

    return 0;
}

//Implementacion
void play( int min_val, int max_val)
{   std::random_device rd;
    std::mt19937 gen(10);
    std::uniform_int_distribution<int> distro(min_val, max_val)

    const int NUM = distro(gen);
    int guessed_number = NUM/2;

    const int MIN = min_val;
    const int MAX = max_val;

    std::cout << "INICIA EL JUEGO \n";

    while(guessed_number != NUM ){
        std::cout << "Adivina un numero entre "<< MIN <<" y "<< MAX <<":\n";
        std::cin >> guessed_number;
        std::cout << "Escribiste: " << guessed_number <<"\n";

        // Validacion del rango

        if (guessed_number < MIN or MAX < guessed_number){
            std::cout << "Recuerda entre 1 y 100 \n";
            continue;
        }
        if (guessed_number == NUM){
            std::cout << "Ganaste!!!\n";
            break;
        } else if (guessed_number > NUM){
            std::cout << "No ganaste, tu numero es muy grande \n";
        } else { // es menor
            std::cout << "Te falta \n";
        }
    }
}