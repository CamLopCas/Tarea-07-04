#include "derivatives.h"  // Incluye las declaraciones de las funciones
#include <cmath>          // Para std::pow

/**
 * Calcula la derivada usando diferencia hacia adelante
 *  x Punto donde se evalúa la derivada
 *  h Tamaño del paso (incremento)
 *  f Función a derivar (de tipo fptr)
 *  Aproximación de f'(x) usando [f(x+h)-f(x)]/h
 * 
 * Error: O(h) - lineal con el tamaño del paso
 */
double forward_diff(double x, double h, fptr f) {
    return (f(x + h) - f(x)) / h;
}

/**
 * Calcula la derivada usando diferencia central
 *  x Punto donde se evalúa la derivada
 *  h Tamaño del paso (incremento)
 *  f Función a derivar (de tipo fptr)
 *  Aproximación de f'(x) usando [f(x+h)-f(x-h)]/(2h)
 * 
 * Error: O(h²) - cuadrático con el tamaño del paso
 */
double central_diff(double x, double h, fptr f) {
    return (f(x + h) - f(x - h)) / (2*h);
}

/**
 * Implementa la extrapolación de Richardson para mejorar aproximaciones de derivadas
 *  x Punto donde se evalúa la derivada
 *  h Tamaño del paso inicial
 *  f Función a derivar
 *  alg Algoritmo base (forward_diff o central_diff)
 *  alpha Orden de convergencia del algoritmo (1 para forward, 2 para central)
 *  Mejor aproximación de f'(x) usando extrapolación
 * 
 * Técnica: Combina dos evaluaciones con diferentes h para cancelar términos de error
 */
double richardson(double x, double h, fptr f, algptr alg, int alpha) {
    double aux = std::pow(2.0, alpha);  // Factor 2^alpha
    double val1 = alg(x, h, f);        // Evaluación con paso h
    double val2 = alg(x, h/2.0, f);    // Evaluación con paso h/2
    return (aux*val2 - val1)/(aux - 1.0);  // Combinación para reducir error
}