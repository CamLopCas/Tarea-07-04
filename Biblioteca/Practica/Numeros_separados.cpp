#include <iostream>


int main() {
    // Declaración de variables
    int numero_ingresado; // Almacena el número que ingresa el usuario
    
    // Solicitar entrada al usuario
    std::cout << "Ingrese un numero: ";
    std::cin >> numero_ingresado;
    
    // Contar la cantidad de dígitos del número
    int copia_numero = numero_ingresado; // Copia para no modificar el original
    int cantidad_digitos = 0; // Contador de dígitos
    
    // El bucle se ejecuta hasta que no queden más dígitos
    while (copia_numero != 0) {
        copia_numero = copia_numero / 10; // Elimina el último dígito
        cantidad_digitos++; // Incrementa el contador
    }
    
    // Crear un array con el tamaño exacto de dígitos
    int digitos[cantidad_digitos]; // Array para almacenar los dígitos
    copia_numero = numero_ingresado; // Restablecer la copia
    
    // Extraer dígitos y almacenarlos en orden correcto
    for (int posicion = cantidad_digitos - 1; posicion >= 0; posicion--) {
        digitos[posicion] = copia_numero % 10; // Obtiene el último dígito
        copia_numero = copia_numero / 10; // Elimina el último dígito
    }
    
    // Mostrar los dígitos separados por espacios
    std::cout << "Digitos separados: ";
    for (int i = 0; i < cantidad_digitos; i++) {
        std::cout << digitos[i]; // Imprime el dígito actual
        
        // Agrega espacio si no es el último dígito
        if (i < cantidad_digitos - 1) {
            std::cout << " ";
        }
    }
    std::cout << "\n"; // Salto de línea final
    
    return 0; // Indica que el programa terminó correctamente
}