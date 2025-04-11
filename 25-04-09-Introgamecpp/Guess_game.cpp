/*JUego de adivinar un numero
Tener un numero
Preguntar al usuario un numero
Informar si lo adivinio o no
*/

#include <iostream>

int main(void){
    const int NUM = 10;
    int guessed_number = NUM/2;

    const int MIN = 1;
    const int MAX = 100;

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

    return 0;
}
