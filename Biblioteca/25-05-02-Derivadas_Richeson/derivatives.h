#pragma once  // Directiva para evitar inclusiones múltiples

#include <cmath>       // Para funciones matemáticas estándar
#include <functional>  // Para std::function (función generalizada)

// Alias para funciones que toman double y devuelven double
using fptr = std::function<double(double)>;

/**
 * Calcula la derivada numérica usando diferencia hacia adelante
 *  x Punto donde se evalúa la derivada
 *  h Tamaño del paso (incremento)
 *  f Función a derivar (de tipo fptr)
 *  Aproximación de f'(x) usando [f(x+h)-f(x)]/h
 */
double forward_diff(double x, double h, fptr f);

/**
 * Calcula la derivada numérica usando diferencia central
 *  x Punto donde se evalúa la derivada
 *  h Tamaño del paso (incremento)
 *  f Función a derivar (de tipo fptr)
 *  Aproximación de f'(x) usando [f(x+h)-f(x-h)]/(2h)
 */
double central_diff(double x, double h, fptr f);

// Alias para algoritmos de derivación numérica
using algptr = std::function<double(double, double, fptr)>;

/**
 * Implementa la extrapolación de Richardson para mejorar aproximaciones de derivadas
 *  x Punto donde se evalúa la derivada
 *  h Tamaño del paso inicial
 *  f Función a derivar
 *  alg Algoritmo base (forward_diff o central_diff)
 *  alpha Orden de convergencia del algoritmo (1 para forward, 2 para central)
 *  Mejor aproximación de f'(x) usando extrapolación
 */
double richardson(double x, double h, fptr f, algptr alg, int alpha);