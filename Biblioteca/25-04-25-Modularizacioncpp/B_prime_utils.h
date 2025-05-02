#pragma once  // Directiva del preprocesador para evitar inclusiones múltiples

#include <iostream>  // Para std::cerr (usado en la implementación)
#include <cmath>     // Para std::sqrt (usado en la implementación)

// Declaración de la función que verifica si un número es primo
// Parámetros:
//   - n: número de tipo long a verificar
// Retorno:
//   - bool: true si n es primo, false si no lo es
bool isprime(long n);