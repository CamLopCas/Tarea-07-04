// Incluye la biblioteca estándar de entrada/salida de C++.
// <iostream> permite usar funciones como:
// - std::cout (para imprimir en consola)
// - std::cin (para leer entrada del usuario)
#include <iostream>

// 'main' es la función OBLIGATORIA donde comienza la ejecución del programa.
// 'int' indica que esta función debe devolver un número entero al terminar.
// '(void)' especifica explícitamente que NO recibe parámetros (opcional en C++ moderno).
int main(void) { 
    // 'std::cout' es el flujo de salida estándar (consola).
    // '<<' es el operador de inserción (envía datos a la salida).
    // "Hola!\n" es el texto a imprimir:
    // - '\n' es un salto de línea (equivalente a std::endl pero más eficiente).
    std::cout << "Hola!\n";

    // 'return 0' indica al sistema operativo que el programa terminó CORRECTAMENTE.
    // Convención: 0 = éxito, cualquier otro valor = código de error.
    return 0;
}
