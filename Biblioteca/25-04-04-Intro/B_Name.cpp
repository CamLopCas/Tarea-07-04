// Incluye la biblioteca estándar para operaciones de entrada/salida (cout, cin)
#include <iostream>
// Incluye la biblioteca para usar el tipo de dato 'string' (manejo de cadenas de texto)
#include <string>

// Función principal del programa
// 'int' indica que retornará un valor entero (0 = éxito)
// '(void)' explícita que no recibe parámetros (opcional en C++ moderno)
int main(void) { 
    // Declara una variable 'name' de tipo string para almacenar el nombre del usuario
    std::string name;
    
    // Imprime un mensaje preguntando el nombre
    // '\n' inserta un salto de línea (más eficiente que std::endl)
    std::cout << "Hello, whats your name?\n";
    
    // Declara una variable 'age' de tipo string para almacenar la edad (como texto)
    std::string age;
    
    // Alternativa comentada: cin >> name solo lee hasta el primer espacio
    // std::cin >> name;
    
    // getline() lee TODA la línea (incluyendo espacios) y la guarda en 'name'
    // Primer parámetro: std::cin (entrada estándar)
    // Segundo parámetro: variable donde se almacenará (name)
    std::getline(std::cin, name);
    
    // Imprime saludo personalizado y pregunta la edad
    // Concatena textos con el operador <<
    std::cout << "Hello," << name << " How old are you?\n";
    
    // Lee la edad (como texto) con getline() para capturar toda la línea
    std::getline(std::cin, age);
    
    // Imprime la edad con formato:
    // '\t' añade una tabulación al inicio
    // '<<' concatena variables y textos
    std::cout << "\tGreat your age is " << age << " .Tell me, where do you live?\n";
    
    // Retorno estándar (0 = éxito)
    return 0;
}